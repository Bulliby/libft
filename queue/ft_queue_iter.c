/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_queue_iter.c                                                          */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2020/11/08 14:42:11 by bulliby            \     \_\ \     /     */
/*   Updated: 2020/11/08 15:03:35 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_queue_iter(t_queue *queue, void (*f)(t_queue_node *elem)) 
{
    t_queue_node *lst;
    lst = queue->start;

    while(lst) {
		(*f)(lst);
        lst = lst->next; 
    }
}
