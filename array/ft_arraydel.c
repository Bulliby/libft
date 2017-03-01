/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:26:40 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:26:41 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arraydel(t_array *array, size_t index)
{
	if (array->len > 1)
		ft_arrayswap(array, array->len - 1, index);
	array->len--;
}
