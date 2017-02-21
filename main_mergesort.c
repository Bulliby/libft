#include "includes/libft.h"

static void				print(t_pile *elem)
{
	printf("[%i]", *(int*)elem->content);
}

static t_bool				cmp(void *a, void *b)
{
	if (*(int*)a <= *(int*)b)
		return true;
	else
		return false;
}

int				main(void)
{
	int			toto;
	t_pile		*mystack;
	t_pile		*mystack_sorted;
	t_pile		*node;	

	mystack = NULL;
	toto = 5;
	node = ft_pilenew(&toto, sizeof(int));
	ft_pilepush(&mystack, node);	
	toto = 4;
	node = ft_pilenew(&toto, sizeof(int));
	ft_pilepush(&mystack, node);	
	toto = 10;
	node = ft_pilenew(&toto, sizeof(int));
	ft_pilepush(&mystack, node);	
	toto = 2;
	node = ft_pilenew(&toto, sizeof(int));
	ft_pilepush(&mystack, node);	
	toto = 6;
	node = ft_pilenew(&toto, sizeof(int));
	ft_pilepush(&mystack, node);	
	toto = 8;
	node = ft_pilenew(&toto, sizeof(int));
	ft_pilepush(&mystack, node);	
	toto = 9;
	node = ft_pilenew(&toto, sizeof(int));
	ft_pilepush(&mystack, node);	
	mystack_sorted = ft_mergesort(&mystack, cmp);
	ft_pileiter(mystack_sorted, print);
}
