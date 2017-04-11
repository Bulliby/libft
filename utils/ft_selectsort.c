/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selectsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:23:48 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:24:00 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			unsorted_supress(t_array *base, size_t index)
{
	if (base->len > 0)
		base->data[index] = base->data[base->len - 1];
	base->len--;
}

t_array				*ft_selectsort(t_array *base, size_t (*select)\
					(void **data, const size_t len))
{
	t_array			*ret;
	size_t			i;
	size_t			index;
	const size_t	len = base->len;

	i = 0;
	ret = ft_arrayinit(len);
	while (i != len)
	{
		index = (*select)(base->data, base->len);
		ft_arrayadd(ret, base->data[index], ret->len);
		unsorted_supress(base, index);
		i++;
	}
	return (ret);
}
