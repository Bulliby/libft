/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:54:53 by gwells            #+#    #+#             */
/*   Updated: 2016/10/16 02:33:35 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *ret;
	int	 i;
	
	i = 0;
	ret = ft_malloc(size);
	(void)count;
	while (i != (int)size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
