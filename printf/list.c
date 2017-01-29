/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 09:22:35 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 11:03:48 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*new_elem(char *str)
{
	t_node	*new;

	new = (t_node*)ft_memalloc_fail(sizeof(t_node));
	new->opt = (t_args*)ft_memalloc_fail(sizeof(t_args));
	new->str = str;
	new->next = NULL;
	return (new);
}

void		pushback(t_node **begin, t_node *new)
{
	t_node	*string;

	string = *begin;
	if (*begin == NULL)
		*begin = new;
	else
	{
		while (string->next)
			string = string->next;
		string->next = new;
	}
}
