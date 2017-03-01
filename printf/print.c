/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 10:56:02 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:12:53 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		printf_putnchar(char c, int n)
{
	static long long int count = 0;

	if (c == 1)
		count = 0;
	if (c == 2)
	{
		count += n;
		return (count);
	}
	while (n > 0)
	{
		ft_putchar(c);
		count++;
		n--;
	}
	return (count);
}

void	putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf_putnchar(str[i], 1);
		i++;
	}
}

void	putnstr(char *str, int n)
{
	int i;

	i = 0;
	while (str[i] && i < n)
	{
		printf_putnchar(str[i], 1);
		i++;
	}
}

void	putswchar(wchar_t *str)
{
	while (*str)
	{
		print_wchar(*str);
		str++;
	}
}
