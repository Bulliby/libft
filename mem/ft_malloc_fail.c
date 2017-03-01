/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_fail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:06:48 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:06:50 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_malloc_fail(size_t size)
{
	void		*mem;

	if (!(mem = malloc(size)))
		ft_quit("Malloc failed", 2, EXIT_FAILURE);
	return (mem);
}
