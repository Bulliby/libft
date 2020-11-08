/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_queue_pop.c                                                           */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2020/11/08 12:23:42 by bulliby            \     \_\ \     /     */
/*   Updated: 2020/11/08 15:30:17 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue_node *ft_queue_pop(t_queue *queue)
{
	t_queue_node *ret;

	ret = queue->end;
	queue->end = queue->end->prev;
	if (queue->end) {
		queue->end->next = NULL;
	} else {
		queue->start = NULL;
	}

	return ret;
}
