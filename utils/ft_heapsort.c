/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:00:06 by gwells            #+#    #+#             */
/*   Updated: 2017/02/09 11:15:58 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array					*ft_heapsort(t_pq *pq)
{
	t_array				*ret;

	ret = ft_arrayinit(pq->len);
	while (pq->len > 1)
	{	
		//ft_arrayadd(ret, pq->data[1] , ret->len);
		ft_pqsupress(pq);
	}
	return (ret);
}
