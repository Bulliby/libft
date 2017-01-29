/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 10:22:57 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 12:33:07 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		putsnwchar(wchar_t *str, int n)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && j < n)
	{
		if ((j + wchar_real_len(str[i])) <= n)
			print_wchar(str[i]);
		j += wchar_real_len(str[i]);
		i++;
	}
}

int			wcharnlen(wchar_t *str, int n)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (count + wchar_real_len(str[i]) <= n)
			count += wchar_real_len(str[i]);
		i++;
	}
	return (count);
}

int			wcharlen(wchar_t *str, int type)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	(void)type;
	while (str[i])
	{
		count += wchar_real_len(str[i]);
		i++;
	}
	return (count);
}

int			wchar_real_len(wchar_t chara)
{
	if (chara < 0x7F)
		return (1);
	else if (chara <= 0x7FF)
		return (2);
	else if (chara <= 0xFFFF)
		return (3);
	else if (chara <= 0x10FFFF)
		return (4);
	else
		return (0);
}

void		print_wchar(wchar_t chara)
{
	if (chara < 0x7F)
	{
		printf_putnchar(chara, 1);
	}
	else if (chara <= 0x7FF)
	{
		printf_putnchar((chara >> 6) + 0xC0, 1);
		printf_putnchar((chara & 0x3F) + 0x80, 1);
	}
	else if (chara <= 0xFFFF)
	{
		printf_putnchar((chara >> 12) + 0xE0, 1);
		printf_putnchar(((chara >> 6) & 0x3F) + 0x80, 1);
		printf_putnchar((chara & 0x3F) + 0x80, 1);
	}
	else if (chara <= 0x10FFFF)
	{
		printf_putnchar((chara >> 18) + 0xF0, 1);
		printf_putnchar(((chara >> 12) & 0x3F) + 0x80, 1);
		printf_putnchar(((chara >> 6) & 0x3F) + 0x80, 1);
		printf_putnchar((chara & 0x3F) + 0x80, 1);
	}
}
