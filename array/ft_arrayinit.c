/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:25:24 by gwells            #+#    #+#             */
/*   Updated: 2017/02/08 08:58:58 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array				*ft_arrayinit(size_t len)
{
	t_array			*ret;

	ret = ft_memalloc_fail(sizeof(t_array));
	ret->alloc = len / SIZE + 1;
	ret->len = 0;
	ret->data = ft_memalloc_fail(ret->alloc * ARRAY_DEFAULT_ALLOC);
	return (ret);
}
