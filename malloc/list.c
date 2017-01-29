/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:57:08 by gwells            #+#    #+#             */
/*   Updated: 2016/10/05 18:15:50 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	block_too_large(t_mem *blocks, t_size area, size_t size)
{
	if (blocks->current_block[area] + sizeof(t_block) + size >\
	blocks->end_of_block[area] || blocks->current_block[area] + \
	sizeof(t_block) > blocks->end_of_block[area])
		return (true);
	return (false);
}

void			iter_block(t_size area, void (*f)(t_block *tmp, size_t size))
{
	t_block		*tmp;
	t_mem		*s;

	s = singleton();
	tmp = (t_block*)s->block_start[area];
	while (tmp && tmp->addr)
	{
		f(tmp, tmp->size);
		tmp = tmp->next;
	}
}

void			*add_block(t_mem *blocks, t_size area, size_t size)
{
	t_block		*new_block;

	if ((new_block = check_for_free(blocks, area, size)))
		return (new_block);
	if (block_too_large(blocks, area, size))
		re_populate_stock(blocks, area);
	new_block = (t_block*)blocks->current_block[area];
	new_block->addr = (char*)new_block + sizeof(t_block) + 1;
	new_block->free = false;
	new_block->size = size;
	blocks->current_block[area] += sizeof(t_block) + size + 1;
	new_block->next = (t_block*)blocks->current_block[area];
	return (new_block->addr);
}

void			*choose_alloc(t_mem *s, size_t size)
{
	if (size < TINY_LIMIT)
		return (add_block(s, TINY, size));
	else if (size < SMALL_LIMIT)
		return (add_block(s, SMALL, size));
	else
		return (add_large_stock(s, size));
}
