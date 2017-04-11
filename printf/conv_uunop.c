/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_uunop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 11:54:13 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:12:19 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			conv_p(va_list *ap, t_node *node)
{
	intmax_t	adress;
	int			len;

	adress = va_arg(*ap, intmax_t);
	len = ft_nbrlen(adress, 16);
	put_prefix(node, "0x", len, 1);
	if (node->opt->minus)
		putstr("0x");
	if ((node->opt->got_preci && node->opt->preci) || !node->opt->got_preci)
		ft_putnbrbase(adress, "0123456789abcdef", 16);
	if (node->opt->minus)
		pad_width(node, "0x", len, ' ');
}

void			no_conv(va_list *ap, t_node *node, int pos)
{
	(void)ap;
	if (!node->opt->minus)
		c_pad_width(1, node);
	if (pos - 1 != 0)
		printf_putnchar(node->opt->conv, 1);
	if (node->opt->minus)
		c_pad_width(1, node);
}

void			conv_unsigned(va_list *ap, t_node *node)
{
	uintmax_t	nbr;
	int			len;

	nbr = get_unsigned(ap, node);
	len = ft_nbrlen(nbr, 10);
	put_prefix(node, "", len, 1);
	if ((node->opt->got_preci && node->opt->preci) || !node->opt->got_preci)
		ft_putnbrbase(nbr, "0123456789", 10);
	if (node->opt->minus)
		pad_width(node, "", len, ' ');
}

void			conv_unsignedl(va_list *ap, t_node *node)
{
	node->opt->e_length = l;
	conv_unsigned(ap, node);
}
