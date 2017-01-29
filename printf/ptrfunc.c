/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 10:49:12 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 10:49:16 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_conv(char c)
{
	if (ft_strchr("sSpdDioOuUxXcC", c))
		return (1);
	return (0);
}

void		setup_ptrfunc(t_func *ptrfunc)
{
	ptrfunc['d'] = conv_int;
	ptrfunc['D'] = conv_intl;
	ptrfunc['i'] = conv_int;
	ptrfunc['x'] = conv_hexa;
	ptrfunc['X'] = conv_hexa;
	ptrfunc['o'] = conv_octal;
	ptrfunc['O'] = conv_octall;
	ptrfunc['U'] = conv_unsignedl;
	ptrfunc['u'] = conv_unsigned;
	ptrfunc['s'] = conv_s;
	ptrfunc['S'] = conv_wchar;
	ptrfunc['c'] = conv_char;
	ptrfunc['C'] = conv_wcharc;
	ptrfunc['p'] = conv_p;
}
