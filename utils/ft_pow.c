/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:15:08 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:15:08 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_pow(int number, int pow)
{
	if (pow < 0)
		return (1 / ft_pow(number, -pow));
	else if (pow == 0)
		return (1);
	else if (!(pow % 2))
		return (ft_pow(number * number, pow / 2));
	else
		return (number * ft_pow(number * number, (pow - 1) / 2));
}
