/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsupress_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 17:45:09 by gwells            #+#    #+#             */
/*   Updated: 2016/05/09 19:46:14 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//check memory

char		*ft_strsupress_at(char *str, size_t pos)
{
	char	*ret;

	ret = ft_memalloc_fail(sizeof(char) * ft_strlen(str));
	ret = ft_strncpy(ret, str, pos);
	pos++;
	while (*str && pos--)
		str++;
	ret = ft_strjoin(ret, str);
	return (ret);	
}
