/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:49:18 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 10:49:20 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrayswap(t_array *array, size_t a, size_t b)
{
	void	*tmp;

	tmp = array->data[a];
	array->data[a] = array->data[b];
	array->data[b] = tmp;
}
