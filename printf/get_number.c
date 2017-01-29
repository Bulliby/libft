/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/13 12:25:46 by gwells            #+#    #+#             */
/*   Updated: 2015/05/13 16:35:18 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	get_signed(va_list *ap, t_node *node)
{
	intmax_t nbr;

	nbr = va_arg(*ap, intmax_t);
	if (node->opt->e_length == hh)
		nbr = (char)nbr;
	else if (node->opt->e_length == h)
		nbr = (short int)nbr;
	else if (node->opt->e_length == l)
		nbr = (long int)nbr;
	else if (node->opt->e_length == ll)
		nbr = (long long int)nbr;
	else if (node->opt->e_length == j)
		nbr = (intmax_t)nbr;
	else if (node->opt->e_length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t	get_unsigned(va_list *ap, t_node *node)
{
	intmax_t nbr;

	nbr = va_arg(*ap, uintmax_t);
	if (node->opt->e_length == hh)
		nbr = (unsigned char)nbr;
	else if (node->opt->e_length == h)
		nbr = (unsigned short int)nbr;
	else if (node->opt->e_length == l)
		nbr = (unsigned long int)nbr;
	else if (node->opt->e_length == ll)
		nbr = (unsigned long long int)nbr;
	else if (node->opt->e_length == j)
		nbr = (uintmax_t)nbr;
	else if (node->opt->e_length == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
