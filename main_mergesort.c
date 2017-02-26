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

int				main(int argc, char **argv)
{
	int			toto;
	t_pile		*mystack;
	t_pile		*mystack_sorted;
	t_pile		*node;	

	mystack = NULL;
	while (argc - 1 != 0)
	{
		toto = ft_atoi(argv[argc - 1]);
		node = ft_pilenew(&toto, sizeof(int));
		ft_pilepush(&mystack, node);	
		argc--;
	}
	ft_pileiter(mystack, print);
	mystack_sorted = ft_mergesort(&mystack, cmp);
	ft_pileiter(mystack_sorted, print);
}
