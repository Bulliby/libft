/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsupress_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 18:52:00 by gwells            #+#    #+#             */
/*   Updated: 2016/09/26 15:49:23 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void handle_extremity(t_dlist *lst, t_dnode *to_supress)
{
	if (lst->head == to_supress && lst->queue == to_supress)
	{
		lst->head = NULL; 
		lst->queue = NULL;
	}
	else if (lst->head == to_supress)
	{
		lst->head = lst->head->next;
		lst->head->prev = lst->queue;
		lst->queue->next = lst->head;
		if (lst->length == 2)
			lst->head->next = lst->head;
	}
	else if (lst->queue == to_supress)
	{
		lst->queue = lst->queue->prev;
		lst->queue->next = lst->head;
		lst->head->prev = lst->queue;
		if (lst->length == 2)
			lst->queue->prev = lst->queue;
	}
}

void		ft_dlstsupress_at_circ(t_dlist *lst, t_dnode *to_supress, void (*del)(void *, size_t))
{
	t_dnode *tmp;
	int		lst_size;

	if (lst->head == to_supress || lst->queue ==  to_supress)
		handle_extremity(lst, to_supress);
	else
	{
		tmp = lst->head;
		lst_size = lst->length;
		while (tmp && lst_size)
		{
			if (tmp == to_supress)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			tmp = tmp->next;
			lst_size--;
		}
	}
	lst->length--;
	ft_dlstdelone(&to_supress, del);
}
