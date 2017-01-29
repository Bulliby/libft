/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:52:54 by gwells            #+#    #+#             */
/*   Updated: 2016/10/12 16:13:39 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*add_large_stock(t_mem *blocks, size_t size)
{
	void			*ret;
	t_block			*tmp;
	t_block			*new_block;

	tmp = (t_block*)blocks->current_block[LARGE];
	if ((ret = mmap(NULL, sizeof(t_block) + size, PROT_READ | PROT_WRITE,\
	MAP_ANON | MAP_PRIVATE, -1, 0)) == NULL)
		return (NULL);
	if (blocks->block_start[LARGE] == NULL)
		blocks->block_start[LARGE] = ret;
	blocks->current_block[LARGE] = ret;
	new_block = (t_block*)blocks->current_block[LARGE];
	new_block->addr = (char*)new_block + sizeof(t_block) + 1;
	new_block->size = size;
	new_block->free = false;
	if (tmp != NULL)
		tmp->next = (t_block*)blocks->current_block[LARGE];
	return (new_block->addr);
}

static void			*init_stock(t_mem *blocks, t_size area)
{
	void			*ret;

	ret = mmap(NULL, (area == TINY) ? TINY_BLOCK : SMALL_BLOCK,\
	PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	blocks->current_block[area] = ret;
	blocks->end_of_block[area] = blocks->current_block[area] +\
	((area == TINY) ? TINY_BLOCK : SMALL_BLOCK);
	return (ret);
}

void				re_populate_stock(t_mem *blocks, t_size area)
{
	void			*ret;
	t_block			*tmp;

	tmp = (t_block*)blocks->current_block[area];
	ret = init_stock(blocks, area);
	tmp->next = (t_block*)blocks->current_block[area];
}

void				*init_all_stock(t_mem *s)
{
	t_size			area;

	area = TINY;
	while (area != LARGE)
	{
		s->block_start[area] = init_stock(s, (t_size)area);
		if (s->block_start[area] == MAP_FAILED)
			return (NULL);
		area++;
	}
	s->block_start[LARGE] = NULL;
	s->current_block[LARGE] = NULL;
	return (s);
}
