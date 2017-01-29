/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 11:53:42 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 11:53:45 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		wchar_pad_width(int len, t_node *node)
{
	if (!node->opt->got_preci)
		node->opt->width -= len;
	else if (node->opt->preci < len)
	{
		node->opt->width -= node->opt->preci;
	}
	else
		node->opt->width -= len;
	if (node->opt->width > 0)
	{
		if (!node->opt->zero)
			printf_putnchar(' ', node->opt->width);
		else
			printf_putnchar('0', node->opt->width);
	}
}

void			conv_wchar(va_list *ap, t_node *node)
{
	wchar_t		*arg;
	int			len;
	int			len2;

	arg = va_arg(*ap, wchar_t*);
	if (!arg)
	{
		putstr("(null)");
		return ;
	}
	len = wcharlen(arg, 0);
	if (node->opt->got_preci && node->opt->preci < len)
		len2 = wcharnlen(arg, node->opt->preci);
	if (!node->opt->minus)
		wchar_pad_width((node->opt->got_preci && node->opt->preci < len) \
				? len2 : len, node);
	if (node->opt->got_preci && node->opt->preci < len)
		putsnwchar(arg, node->opt->preci);
	else
		putswchar(arg);
	if (node->opt->minus)
		wchar_pad_width((node->opt->got_preci && node->opt->preci < len) \
				? len2 : len, node);
}
