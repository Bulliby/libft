/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 15:53:19 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 10:49:01 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			is_opt(char c)
{
	char			*authorized;

	authorized = ft_strdup("#-+0123456789hljz. ");
	if (ft_strchr(authorized, c))
	{
		free(authorized);
		return (1);
	}
	else
	{
		free(authorized);
		return (0);
	}
}

void				split(char *format, t_node **begin)
{
	int				i;
	int				h;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			h = i;
			i++;
			while (format[i] && is_opt(format[i]))
				i++;
			pushback(begin, new_elem(ft_strsub(format, h, i - h + 1)));
			h = i;
			if (format[i])
				i++;
		}
		else
		{
			h = i;
			while (format[i] && format[i] != '%')
				i++;
			pushback(begin, new_elem(ft_strsub(format, h, i - h)));
		}
	}
}
