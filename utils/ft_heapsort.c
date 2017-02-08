/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:00:06 by gwells            #+#    #+#             */
/*   Updated: 2017/02/08 09:32:40 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array					*ft_heapsort(t_mdata_pq *md)
{
	t_mdata_array		*ret;

	ret = ft_arrayinit(100);
	while (md->nb_cases > 0)
	{	
		ft_arrayadd(ret, ft_arraycreate(md->start[1]->content, md->start[1]\
		->content_size), 0);
		ft_pqsupress(md);
	}
	return (ret);
}
