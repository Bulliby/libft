/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:14:09 by gwells            #+#    #+#             */
/*   Updated: 2016/10/02 14:27:10 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	char			*ret;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	else if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		ret = ft_memalloc_fail(size);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
		return (ret);
	}
	return (NULL);
}
