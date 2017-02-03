#include "includes/libft.h"

static void				print_array(t_array *elem)
{
	printf("%i", *(int*)elem->content);
}

int					main(int argc, char **argv)
{
	t_mdata_array	*md;
	t_array			*array;
	int				toto;
	size_t			i;

	i = 0;
	toto = 5;
	md = ft_arrayinit(1023);
	/*
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 0);
	toto = 4;
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 1);
	toto = 6;
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 2);
	toto = 7;
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 3);
	ft_arrayiter(md->start, md->nb_cases, print_array);
	ft_arraysupress(md, 2, ft_sorted_supress);
	ft_arrayiter(md->start, md->nb_cases, print_array);
	ft_arraydestroy(md);
	*/
	while (i != SIZE)
	{
		ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), i);
		i++;
	}
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 3);
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 3);
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 3);
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 3);
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 3);
	ft_arrayadd(md, ft_arraycreate(&toto, sizeof(int)), 3);
	ft_arrayiter(md->start, md->nb_cases, print_array);
	ft_arraydestroy(md);
	return (0);
}
