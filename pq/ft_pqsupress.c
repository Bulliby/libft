/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqsupress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:16 by gwells            #+#    #+#             */
/*   Updated: 2017/02/06 14:18:31 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_index_lil_child(t_mdata_pq *md, size_t index)
{
	size_t			ret;

	if (index * 2 + 1 <= md->nb_cases && md->cmp(md->start[index * 2]->content,\
		md->start[index * 2 + 1]->content) >= 0)
		ret = index * 2 + 1;
	else
		ret = index * 2;
	return (ret);
}

static void			swap(t_mdata_pq *md, size_t index)
{
	size_t			lil_child;

	if (index * 2 <= md->nb_cases)
	{
		lil_child = get_index_lil_child(md, index);
		if (lil_child <= md->nb_cases && md->cmp(md->start[index]->content, \
			md->start[lil_child]->content) >= 0)
		{
			ft_pqswap(md->start, index, lil_child);
			swap(md, lil_child);
		}	
	}
}

void				ft_pqsupress(t_mdata_pq *md)
{
	ft_pqswap(md->start, 1, md->nb_cases);
	md->nb_cases--;
	swap(md, 1);
}
