/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:09:17 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:09:18 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pq			*ft_pqinit(size_t len, int (*cmp)(void *, void *))
{
	t_pq		*pq;

	pq = ft_malloc_fail(sizeof(t_pq));
	pq->alloc = len / SIZE + 1;
	pq->data = ft_memalloc_fail(pq->alloc * ARRAY_DEFAULT_ALLOC);
	pq->len = 1;
	pq->cmp = (*cmp);
	return (pq);
}
