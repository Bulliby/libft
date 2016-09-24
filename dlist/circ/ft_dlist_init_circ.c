#include "../../libft.h"

void	ft_init_node_circ(t_dlist *lst, t_dnode *newnode)
{
	lst->head = newnode;
	lst->queue = newnode;
	lst->head->next = newnode;
	lst->head->prev = newnode;
	lst->queue->prev = newnode;
	lst->head->next = newnode;	
}
