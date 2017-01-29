/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:41:09 by gwells            #+#    #+#             */
/*   Updated: 2016/10/12 14:43:49 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			print(t_block *tmp, size_t size)
{
	char		*start;
	char		*end;

	start = (char*)tmp;
	if ((t_block*)tmp->free == false)
	{
		end = start + sizeof(t_block) + size;
		ft_putstr_fd("Adress [", 1);
		conv_p_malloc((intmax_t)start);
		ft_putstr_fd("]", 1);
		ft_putstr_fd(" -- ", 1);
		ft_putstr_fd("[", 1);
		conv_p_malloc((intmax_t)end);
		ft_putstr_fd("]", 1);
		ft_putstr_fd(" size ", 1);
		ft_putstr_fd("[", 1);
		ft_putnbr_fd(size, 1);
		ft_putstr_fd("]", 1);
		ft_putendl_fd("", 1);
	}
}

void			show_alloc_mem(void)
{
	t_mem		*s;

	s = singleton();
	ft_putstr_fd("TINY [", 1);
	conv_p_malloc((intmax_t)s->block_start[TINY]);
	ft_putstr_fd("]", 1);
	ft_putendl_fd("", 1);
	iter_block(TINY, &print);
	ft_putstr_fd("SMALL [", 1);
	conv_p_malloc((intmax_t)s->block_start[SMALL]);
	ft_putstr_fd("]", 1);
	ft_putendl_fd("", 1);
	iter_block(SMALL, &print);
	ft_putstr_fd("LARGE [", 1);
	conv_p_malloc((intmax_t)s->block_start[LARGE]);
	ft_putstr_fd("]", 1);
	ft_putendl_fd("", 1);
	iter_block(LARGE, &print);
}
