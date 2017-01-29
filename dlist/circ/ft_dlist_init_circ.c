/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_init_circ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 14:09:54 by gwells            #+#    #+#             */
/*   Updated: 2016/10/02 14:10:17 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_node_circ(t_dlist *lst, t_dnode *newnode)
{
	lst->head = newnode;
	lst->queue = newnode;
	lst->head->next = newnode;
	lst->head->prev = newnode;
	lst->queue->prev = newnode;
	lst->head->next = newnode;
}
