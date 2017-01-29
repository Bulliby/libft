/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 11:00:48 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 11:01:42 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		flag(t_node *node)
{
	int			i;

	i = 1;
	while (ft_strchr("#0-+ ", node->str[i]))
	{
		if (node->str[i] == '#')
			node->opt->hash = 1;
		else if (node->str[i] == '-')
			node->opt->minus = 1;
		else if (node->str[i] == '+')
			node->opt->plus = 1;
		else if (node->str[i] == '0')
			node->opt->zero = 1;
		else if (node->str[i] == ' ')
			node->opt->space = 1;
		else
			break ;
		i++;
	}
	return (i);
}

static int		width(t_node *node, int pos)
{
	int			i;
	char		*sub;

	i = pos;
	while (node->str[i] && ft_isdigit(node->str[i]))
		i++;
	sub = ft_strsub(node->str, pos, i - pos);
	node->opt->width = ft_atoi(sub);
	free(sub);
	return (i);
}

static int		precision(t_node *node, int pos)
{
	int			i;
	char		*sub;

	i = pos;
	if (node->str[pos] == '.')
	{
		i++;
		pos++;
		while (node->str[i] && ft_isdigit(node->str[i]))
			i++;
		sub = ft_strsub(node->str, pos, i - pos);
		node->opt->preci = ft_atoi(sub);
		node->opt->got_preci = 1;
		free(sub);
	}
	return (i);
}

static void		length(t_node *node, int pos)
{
	if (node->str[pos])
	{
		if (!ft_strncmp(&(node->str[pos]), "ll", 2))
			node->opt->e_length = ll;
		else if (node->str[pos] == 'l')
			node->opt->e_length = l;
		else if (!ft_strncmp(&(node->str[pos]), "hh", 2))
			node->opt->e_length = hh;
		else if (node->str[pos] == 'h')
			node->opt->e_length = h;
		else if (node->str[pos] == 'j')
			node->opt->e_length = j;
		else if (node->str[pos] == 'z')
			node->opt->e_length = z;
		else
			node->opt->e_length = none;
	}
}

void			parsing(t_node *begin, va_list *ap)
{
	int			pos;
	t_func		ptrfunc[127];

	setup_ptrfunc(ptrfunc);
	while (begin)
	{
		if (begin->str[0] == '%')
		{
			pos = flag(begin);
			pos = width(begin, pos);
			pos = precision(begin, pos);
			length(begin, pos);
			while (begin->str[pos])
				pos++;
			begin->opt->conv = begin->str[pos - 1];
			if (is_conv(begin->str[pos - 1]))
				ptrfunc[(int)begin->str[pos - 1]](ap, begin);
			else
				no_conv(ap, begin, pos);
		}
		else
			putstr(begin->str);
		begin = begin->next;
	}
}
