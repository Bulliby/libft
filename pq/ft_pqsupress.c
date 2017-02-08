/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqsupress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:16 by gwells            #+#    #+#             */
/*   Updated: 2017/02/08 10:55:46 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_index_lil_child(t_pq *pq, size_t index)
{
	size_t			ret;

	if (pq->cmp(pq->data[index * 2], pq->data[index * 2 + 1]) >= 0)
		ret = index * 2 + 1;
	else
		ret = index * 2;
	return (ret);
}

static void			swap(t_pq *pq, size_t index)
{
	size_t			lil_child;

	if (index * 2 + 1 < pq->len)
	{
		lil_child = get_index_lil_child(pq, index);
		if (lil_child <= pq->len && pq->cmp(pq->data[index],\
		pq->data[lil_child]) >= 0)
		{
			ft_pqswap(pq->data, index, lil_child);
			swap(pq, lil_child);
		}	
	}
}

void				ft_pqsupress(t_pq *pq)
{
	ft_pqswap(pq->data, 1, pq->len - 1);
	pq->len--;
	swap(pq, 1);
}
