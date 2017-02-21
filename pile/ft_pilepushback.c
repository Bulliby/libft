/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilepushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 12:03:32 by gwells            #+#    #+#             */
/*   Updated: 2017/02/21 12:14:14 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_pilepushback(t_pile **pile, t_pile *node)
{
	t_pile		*tmp;

	tmp = *pile;
	if (*pile == NULL)
		*pile = node;
	else
	{
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->prev = node;
	}
}
