/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:54:28 by gwells            #+#    #+#             */
/*   Updated: 2016/10/16 02:23:21 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_bool			is_allocated(t_block *start, char *ptr)
{
	while (start)
	{
		if (start->addr == ptr)
			return (true);
		start = start->next;
	}
	return (false);
}

static t_bool	in_large_range(t_mem *blocks, char *ptr)
{
	t_block		*tmp;

	tmp = (t_block*)blocks->block_start[LARGE];
	while (tmp)
	{
		if ((char*)tmp == ptr - sizeof(t_block) - 1)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

t_size			in_range(t_mem *blocks, char *ptr)
{
	t_size		i;

	i = TINY;
	while (i != LARGE)
	{
		if (ptr <= blocks->end_of_block[i] && ptr >= blocks->block_start[i])
			return (i);
		i++;
	}
	if (in_large_range(blocks, ptr))
		return (LARGE);
	return (42);
}

static void		move_alloc(void **ptr, size_t s_before, size_t s_after)
{
	char		*tmp;

	tmp = malloc(s_after);
	((t_block*)((char*)*ptr - sizeof(t_block) - 1))->free = true;
	*ptr = ft_memcpy(tmp, *ptr, s_before + sizeof(t_block));
}

void			*ft_realloc(void *ptr, size_t size)
{
	t_mem		*blocks;
	t_size		range;

	blocks = singleton();
	if ((range = in_range(blocks, (char*)ptr)) != (t_size)42\
		&& is_allocated((t_block*)blocks->block_start[range], ptr))
	{
		if (((t_block*)((char*)ptr - sizeof(t_block) - 1))->size >= size)
			((t_block*)((char*)ptr - sizeof(t_block) - 1))->size = size;
		else
			move_alloc(&ptr, ((t_block*)((char*)ptr - \
			sizeof(t_block) - 1))->size, size);
	}
	else if (ptr == NULL)
		ptr = malloc(size);
	else
		return (NULL);
	return (ptr);
}
