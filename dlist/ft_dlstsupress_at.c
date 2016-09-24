/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsupress_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 18:52:00 by gwells            #+#    #+#             */
/*   Updated: 2016/09/24 22:08:12 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void handle_extremity(t_dlist *lst, t_dnode *to_supress)
{
	if (lst->head == to_supress && lst->queue == to_supress)
	{
		lst->head = NULL; lst->queue = NULL;
		return ;
	}
	if (lst->head == to_supress)
		lst->head = lst->head->next;
	if (lst->queue == to_supress)
		lst->queue = lst->queue->prev;
}

void		ft_dlstsupress_at(t_dlist *lst, t_dnode *to_supress, void (*del)(void *, size_t))
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
