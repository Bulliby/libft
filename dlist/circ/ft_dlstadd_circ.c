/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 14:36:16 by gwells            #+#    #+#             */
/*   Updated: 2016/04/11 20:52:01 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_dlstadd_circ(t_dlist *lst, t_dnode *newnode)
{
	if (lst && newnode)
	{
		if (lst->head == NULL)
			ft_init_node_circ(lst, newnode);
		else
		{
			lst->head->prev = newnode;
			newnode->next = lst->head;
			lst->head = newnode;
			lst->queue->next = newnode;
		}
		lst->length++;
	}
}
