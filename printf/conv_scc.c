/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_scc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 11:53:57 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 11:58:28 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				c_pad_width(int len, t_node *node)
{
	if (!node->opt->got_preci)
		node->opt->width -= len;
	else if (node->opt->preci < len && node->opt->preci != 0)
		node->opt->width -= node->opt->preci;
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

static void			s_pad_width(int len, t_node *node)
{
	if (!node->opt->got_preci)
		node->opt->width -= len;
	else if (node->opt->preci < len)
		node->opt->width -= node->opt->preci;
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

void				conv_s(va_list *ap, t_node *node)
{
	char			*arg;
	int				len;

	if (node->opt->e_length == l)
		conv_wchar(ap, node);
	else
	{
		arg = va_arg(*ap, char*);
		if (!arg && !node->opt->width)
		{
			putstr("(null)");
			return ;
		}
		len = ft_strlen(arg);
		if (!node->opt->minus)
			s_pad_width(len, node);
		if (node->opt->got_preci && arg && node->opt->preci < len)
			putnstr(arg, node->opt->preci);
		else if (arg)
			putstr(arg);
		if (node->opt->minus)
			s_pad_width(len, node);
	}
}

void				conv_wcharc(va_list *ap, t_node *node)
{
	wchar_t			c;

	c = va_arg(*ap, wchar_t);
	if (!node->opt->minus)
		s_pad_width(1, node);
	print_wchar(c);
	if (node->opt->minus)
		s_pad_width(1, node);
}

void				conv_char(va_list *ap, t_node *node)
{
	int				c;

	if (node->opt->e_length == l)
		conv_wcharc(ap, node);
	else
	{
		c = va_arg(*ap, int);
		if (!node->opt->minus)
			c_pad_width(1, node);
		printf_putnchar ((char)c, 1);
		if (node->opt->minus)
			c_pad_width(1, node);
	}
}
