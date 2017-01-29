/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:52:54 by gwells            #+#    #+#             */
/*   Updated: 2016/10/02 14:28:04 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*str_copy;
	int		size;
	int		count;

	str_copy = NULL;
	count = 0;
	size = (int)ft_strlen(str);
	str_copy = ft_memalloc_fail(sizeof(char) * size + 1);
	while (count != size)
	{
		str_copy[count] = str[count];
		count++;
	}
	str_copy[count] = '\0';
	return (str_copy);
}
