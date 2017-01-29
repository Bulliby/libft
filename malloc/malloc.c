/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 19:11:36 by gwells            #+#    #+#             */
/*   Updated: 2016/10/16 17:06:41 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_malloc(size_t size)
{
	static int	flag = 0;
	int			i;
	t_mem		*s;

	s = singleton();
	i = 0;
	if (flag == 0 && init_all_stock(s) == NULL)
		return (NULL);
	flag = 1;
	return (choose_alloc(s, size));
}
