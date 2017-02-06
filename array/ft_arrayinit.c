/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:25:24 by gwells            #+#    #+#             */
/*   Updated: 2017/02/06 14:25:25 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mdata_array		*ft_arrayinit(size_t nb_cases)
{
	t_mdata_array	*md;

	md = ft_memalloc_fail(sizeof(t_mdata_array));
	md->nb_alloc = nb_cases / SIZE + 1;
	md->start = ft_memalloc_fail(md->nb_alloc * ARRAY_DEFAULT_ALLOC);
	md->nb_cases = 0;
	return (md);
}
