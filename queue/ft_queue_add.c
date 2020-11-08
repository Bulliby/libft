/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_queue_add.c                                                           */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2020/11/08 12:23:13 by bulliby            \     \_\ \     /     */
/*   Updated: 2020/11/08 15:21:32 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue *ft_queue_add(t_queue *queue, void *data)
{
    t_queue_node *new, *tmp;

    new = (t_queue_node*)ft_memalloc_fail(sizeof(*new));
    new->content = (void*)ft_memalloc_fail(sizeof(data));

	ft_memcpy(new->content, data, sizeof(data));

    if (queue->start == NULL && queue->end == NULL) {
        queue->start = new;
		queue->end = new;
    } else {
        tmp = queue->start;
		tmp->prev = new;
        queue->start = new;
        new->next = tmp; 
        new->prev = NULL; 
    }

    return queue;
}
