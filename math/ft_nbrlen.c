/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 12:04:39 by gwells            #+#    #+#             */
/*   Updated: 2015/05/06 15:40:41 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_nbrlen(intmax_t nbr, int base)
{
	int count;

	count = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr >= base)
	{
		nbr /= base;
		count++;
	}
	count++;
	return (count);
}
