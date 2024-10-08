/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:09:34 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:10:25 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_pqiter(void **data, size_t nb_cases,\
				void (*f)(void *elem))
{
	size_t		i;

	i = 1;
	while (i != nb_cases)
	{
		(*f)(data[i]);
		i++;
	}
}
