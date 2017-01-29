/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:45:33 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 11:05:40 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(char *format, ...)
{
	t_node	*begin;
	va_list	ap;

	printf_putnchar(1, 0);
	begin = NULL;
	split(format, &begin);
	va_start(ap, format);
	parsing(begin, &ap);
	va_end(ap);
	return (printf_putnchar('c', 0));
}
