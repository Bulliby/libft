/*Test of circ list*/

#include "libft.h"
#include <stdio.h>

static void		del(void *content, size_t size)
{
	printf("YOLO\n");
}

int main(void)
{
	int i;	
	int x;
	int a;
	int z;
	t_dnode *nodex;
	t_dnode *nodei;
	t_dnode *nodea;
	t_dnode *nodez;
	t_dnode	*tmp;
	t_dnode *head;
	t_dnode *queue;
	int		list_size;

	z = 10;
	a = 6;
	x = 8;
	i = 5;
	t_dlist *circ_list;
	circ_list = ft_dlstnew();
	nodei = ft_dlstnewnode_circ(&i, sizeof(int), circ_list); 
	ft_dlstadd_circ(circ_list, nodei);
	nodex = ft_dlstnewnode_circ(&x, sizeof(int), circ_list); 
	ft_dlstadd_circ(circ_list, nodex);
	nodea = ft_dlstnewnode_circ(&a, sizeof(int), circ_list); 
	ft_dlstadd_circ(circ_list, nodea);
	nodez = ft_dlstnewnode_circ(&z, sizeof(int), circ_list); 
	ft_dlstadd_circ(circ_list, nodez);
	tmp = circ_list->head; 
	list_size = circ_list->length;
	while (tmp && list_size--)
	{
		printf("value [%i]\n", (*(int*)tmp->content));
		tmp = tmp->next;
	}
	//ft_dlstsupress_at(circ_list, nodei, del);
	/*
	ft_dlstsupress_at(circ_list, nodex, del);
	ft_dlstsupress_at(circ_list, nodea, del);
	ft_dlstsupress_at(circ_list, nodez, del);
	*/
	ft_dlstsupress_at(circ_list, nodez, del);
	ft_dlstsupress_at(circ_list, nodea, del);
	ft_dlstsupress_at(circ_list, nodex, del);
	tmp = circ_list->head; 
	list_size = circ_list->length;
	printf("lst->head [%p], value [%i]\n", circ_list->head, *(int*)circ_list->head->content);
	printf("lst->queue [%p], value [%i]\n", circ_list->queue, *(int*)circ_list->queue->content);
	printf("next [%p], value [%i]\n", tmp->next, *(int*)tmp->next->content);
	while (tmp && list_size--)
	{
		printf("value [%i]\n", (*(int*)tmp->content));
		tmp = tmp->next;
	}
}
