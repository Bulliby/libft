/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:56:24 by gwells            #+#    #+#             */
/*   Updated: 2016/11/26 11:43:17 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				*check_for_free(t_mem *blocks, t_size area, size_t size)
{
	t_block			*tmp;

	tmp = (t_block*)blocks->block_start[area];
	while (tmp)
	{
		if (tmp->free == true && tmp->size >= size)
		{
			tmp->free = false;
			tmp->size = size;
			return (tmp->addr);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static void			supress_large_block(t_mem *blocks, t_block *blk)
{
	t_block			*tmp;

	tmp = (t_block*)blocks->block_start[LARGE];
	while (tmp->next && tmp->next != blk)
		tmp = tmp->next;
	if (!tmp->next)
		blocks->block_start[LARGE] = NULL;
	else
		tmp->next = blk->next;
}

void				ft_free(void *ptr)
{
	t_mem			*blocks;
	t_size			range;
	t_block			*blk;

	blocks = singleton();
	blk = ((t_block*)(((char*)ptr) - sizeof(t_block) - 1));
	if (ptr != NULL && (range = in_range(blocks, ptr)) != (t_size)42 &&\
	is_allocated((t_block*)blocks->block_start[range], (char*)ptr))
	{
		if (range != LARGE)
			blk->free = true;
		else
		{
			supress_large_block(blocks, blk);
			munmap(blk + 1, blk->size + sizeof(t_block));
		}
	}
}
