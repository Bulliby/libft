/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_OoXx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 11:33:19 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 11:33:22 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*prefix_hash(t_node *node, uintmax_t nbr)
{
	(void)nbr;
	if (node->opt->hash)
	{
		if (node->opt->conv == 'X')
			return ("0X");
		else if (node->opt->conv == 'x')
			return ("0x");
		else
			return ("0");
	}
	else
		return ("");
}

void			conv_octall(va_list *ap, t_node *node)
{
	node->opt->e_length = l;
	conv_octal(ap, node);
}

void			conv_octal(va_list *ap, t_node *node)
{
	uintmax_t	nbr;
	int			len;

	nbr = get_unsigned(ap, node);
	len = ft_nbrlen(nbr, 8);
	put_prefix(node, prefix_hash(node, nbr), len, 0);
	if ((!nbr && node->opt->got_preci && !node->opt->preci) \
		|| (!nbr && node->opt->hash))
		(void)nbr;
	else
		ft_putnbrbase(nbr, "01234567", 8);
	if (node->opt->minus)
		pad_width(node, prefix_hash(node, nbr), len, ' ');
}

void			conv_hexa(va_list *ap, t_node *node)
{
	uintmax_t	nbr;
	int			len;

	nbr = get_unsigned(ap, node);
	len = ft_nbrlen(nbr, 16);
	if (nbr > 0)
		put_prefix(node, prefix_hash(node, nbr), len, 1);
	if ((node->opt->got_preci && node->opt->preci) || !node->opt->got_preci)
	{
		if (node->opt->conv == 'X')
			ft_putnbrbase(nbr, "0123456789ABCDEF", 16);
		else if (node->opt->conv == 'x')
			ft_putnbrbase(nbr, "0123456789abcdef", 16);
	}
	if (node->opt->minus)
		pad_width(node, prefix_hash(node, nbr), len, ' ');
}
