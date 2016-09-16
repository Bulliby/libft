/*Test of circ list*/

#include "libft.h"
#include <stdio.h>

int main(void)
{
	int i;	
	int x;
	int a;
	int z;
	t_dnode *node;
	t_dnode *head;
	t_dnode *queue;

	i = 5;
	x = 8;
	a = 6;
	z = 10;
	t_dlist *circ_list;
	head = ft_dlstnewnode(&i, sizeof(int)); 
	queue = ft_dlstnewnode(&x, sizeof(int)); 
	circ_list = ft_dlstnew_circ(head, queue);
	node = ft_dlstnewnode_circ(&a, sizeof(int), circ_list); 
	ft_dlstpushback_circ(circ_list, node);
	node = ft_dlstnewnode_circ(&z, sizeof(int), circ_list); 
	ft_dlstpushback_circ(circ_list, node);
	while (node)
	{
		printf("value [%i]\n", (*(int*)node->content));
		node = node->next;
	}
}
