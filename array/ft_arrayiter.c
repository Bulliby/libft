/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:25:19 by gwells            #+#    #+#             */
/*   Updated: 2017/02/08 08:35:48 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_arrayiter(void **data, size_t nb_cases,\
				void (*f)(void *elem))
{
	size_t		i;

	i = 0;
	while (i != nb_cases)
	{
		(*f)(data[i]);
		i++;
	}	
}
