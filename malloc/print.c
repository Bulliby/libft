/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 10:17:56 by gwells            #+#    #+#             */
/*   Updated: 2016/10/06 10:35:26 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

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

void			conv_p(intmax_t adress)
{
	int			len;

	len = ft_nbrlen(adress, 16);
	ft_putstr("0x");
	putnbrbase(adress, "0123456789abcdef", 16);
}
