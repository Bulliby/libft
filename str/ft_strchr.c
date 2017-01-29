/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:05:05 by gwells            #+#    #+#             */
/*   Updated: 2016/09/25 14:28:57 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *str, int c)
{
	char	*strchr;

	strchr = NULL;
	while (str && *str != '\0')
	{
		if (*str == c)
		{
			strchr = (char *)str;
			return (strchr);
		}
		str++;
	}
	return (NULL);
}
