/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:41:37 by gwells            #+#    #+#             */
/*   Updated: 2016/12/21 13:41:38 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE 16

static void			base(unsigned char c)
{
	char			ret;
	char			modulo;
	char			stamp[BASE];

	ft_strcpy(stamp, "0123456789ABCDEF");
	ret = c / BASE;
	modulo = c % BASE;
	if (modulo > BASE)
		base(ret);
	ft_putchar(stamp[(int)ret]);
	ft_putchar(stamp[(int)modulo]);
}

void				ft_puthexa(void const *ptr, size_t size)
{
	size_t			i;

	i = 0;
	while (i != size)
	{
		base(((unsigned char *)ptr)[i]);
		i++;
	}
}
