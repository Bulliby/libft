/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:08:53 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:08:54 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		swap(t_pq *pq, size_t index)
{
	if (index > 1 && pq->cmp(pq->data[index], pq->data[index / 2]) <= 0)
	{
		ft_pqswap(pq->data, index, index / 2);
		swap(pq, index / 2);
	}
}

void			ft_pqadd(t_pq *pq, void *elem)
{
	if (pq->len && !(pq->len % SIZE))
		ft_arrayextend((t_array*)pq);
	pq->data[pq->len] = elem;
	pq->len++;
	swap(pq, pq->len - 1);
}
