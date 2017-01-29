/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:54:53 by gwells            #+#    #+#             */
/*   Updated: 2016/11/26 11:39:42 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	i;

	(void)count;
	i = 0;
	ret = ft_malloc(size);
	while (i != size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
