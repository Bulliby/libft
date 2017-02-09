/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 10:17:56 by gwells            #+#    #+#             */
/*   Updated: 2017/02/09 11:55:52 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		putnchar(char c, int n)
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
		ft_putchar_fd(c, 1);
		count++;
		n--;
	}
	return (count);
}

static void		putnbrbase(uintmax_t nbr, char *base, size_t base_len)
{
	if (nbr >= (unsigned int)base_len)
	{
		putnbrbase(nbr / base_len, base, base_len);
		putnbrbase(nbr % base_len, base, base_len);
	}
	else
		putnchar(base[nbr], 1);
}

void			conv_p_malloc(intmax_t adress)
{
	ft_putstr("0x");
	putnbrbase(adress, "0123456789abcdef", 16);
}
