/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayextend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:49:10 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 10:51:53 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_arrayextend(t_array *array)
{
	void			*newdata;

	if (!(array->len % SIZE))
	{
		array->alloc++;
		newdata = ft_memalloc_fail(array->alloc * ARRAY_DEFAULT_ALLOC);
		ft_memcpy(newdata, array->data, (array->alloc - 1) *\
		ARRAY_DEFAULT_ALLOC);
		free(array->data);
		array->data = newdata;
	}
}
