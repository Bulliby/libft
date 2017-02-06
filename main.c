#include "includes/libft.h"

static void				print_array(t_array *elem)
{
	printf("[%i]", *(int*)elem->content);
}

static int				cmp_pq(void *a, void *b)
{
	return (*(int*)b - *(int*)a);
}

int					main(int argc, char **argv)
{
	t_mdata_pq		*md;
	t_mdata_array	*md2;
	int				toto;

	toto = 4;
	md = ft_pqinit(100, cmp_pq);
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 5;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 8;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 11;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 11;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 11;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 10;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 6;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 13;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 12;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 10;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 45;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 32;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 29;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 68;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 22;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 3;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 7;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 70;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 33;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 71;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 0;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 90;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 83;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 86;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	toto = 69;
	ft_pqadd(md, ft_arraycreate(&toto, sizeof(int)));
	md2 = ft_heapsort(md);
	ft_arrayiter(md2->start, md2->nb_cases, print_array);
	return (0);
}
