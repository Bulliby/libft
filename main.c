#include "includes/libft.h"

static void				print_array(t_array *elem)
{
	printf("%i", *(int*)elem->content);
}

static int				cmp_pq(void *a, void *b)
{
	if (*(int*)a >= *(int*)b)
		return (*(int*)a - *(int*)b);
	else
		return (*(int*)a - *(int*)b);
}

int					main(int argc, char **argv)
{
	t_mdata_pq	*md;
	int			toto;

	toto = 6;
	md = ft_pqinit(10, cmp_pq);
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 5;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 10;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 2;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 20;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	ft_pqiter(md->start, md->nb_cases, print_array);
	return (0);
}
