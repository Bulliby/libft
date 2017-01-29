/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 19:12:29 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 11:13:41 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				pad_width(t_node *node, char *pref, int len, char c)
{
	node->opt->width -= ft_strlen(pref);
	if (node->opt->preci > len)
		node->opt->width -= node->opt->preci;
	else
		node->opt->width -= len;
	printf_putnchar(c, node->opt->width);
}

void				pad_preci(t_node *node, int len)
{
	if (node->opt->preci > len)
		printf_putnchar('0', node->opt->preci - len);
}

void				put_prefix(t_node *node, char *pref, int len, int conv)
{
	if (!node->opt->minus)
	{
		if (node->opt->zero && !node->opt->preci)
		{
			putstr(pref);
			pad_width(node, pref, len, '0');
		}
		else
		{
			pad_width(node, pref, len, ' ');
			if (!conv)
			{
				if (node->opt->preci == 0)
					putstr(pref);
			}
			else
				putstr(pref);
		}
	}
	pad_preci(node, len);
}

void				conv_int(va_list *ap, t_node *node)
{
	intmax_t		nbr;
	char			*prefix;
	int				len;

	nbr = get_signed(ap, node);
	len = ft_nbrlen(nbr, 10);
	if (nbr < 0)
	{
		prefix = ft_strdup("-");
		nbr *= -1;
	}
	else if (nbr >= 0 && node->opt->plus)
		prefix = ft_strdup("+");
	else if (node->opt->space)
		prefix = ft_strdup(" ");
	else
		prefix = ft_strdup("");
	put_prefix(node, prefix, len, 1);
	if ((node->opt->got_preci && node->opt->preci) || !node->opt->got_preci)
		ft_putnbrbase(nbr, "0123456789", 10);
	if (node->opt->minus)
		pad_width(node, prefix, len, ' ');
	free(prefix);
}

void				conv_intl(va_list *ap, t_node *node)
{
	node->opt->e_length = l;
	conv_int(ap, node);
}
