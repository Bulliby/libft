#include "includes/libft.h"

static void				print_array(t_array *elem)
{
	printf("[%i]\n", *(int*)elem->content);
}

int					main(int argc, char **argv)
{
	t_mdata_array	*md;
	t_array			*array;
	int				toto;

	toto = 5;
	md = ft_arrayinit(100);
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 0);
	toto = 4;
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 1);
	toto = 6;
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 2);
	toto = 7;
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 3);
	ft_arrayiter(md->start, md->nb_cases, print_array);
	ft_arraysupress(md, 2, ft_sorted_supress);
	printf("deuxieme tab\n");
	ft_arrayiter(md->start, md->nb_cases, print_array);
	ft_arraydestroy(md);
	return (0);
}
