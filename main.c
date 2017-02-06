#include "includes/libft.h"

static void				print_array(t_array *elem)
{
	printf("[%i]", *(int*)elem->content);
}

static int				cmp_pq(void *a, void *b)
{
	return (*(int*)b - *(int*)a);
}

/*
int					main(int argc, char **argv)
{
	int				i;
	int				tmp;
	t_mdata_array	*array;
	t_mdata_pq		*pq;
	
	i = 1;
	pq = ft_pqinit(100, cmp_pq);
	if (argc == 1)
	{
		printf("Entrez des arguments a trier\n");
		exit(42);
	}
	while (i != argc)
	{
		tmp = ft_atoi(argv[i]);
		ft_pqadd(pq, ft_arraycreate(&tmp, sizeof(int)));
		i++;
	}
	array = ft_heapsort(pq);
	ft_arrayiter(array->start, array->nb_cases, print_array);
}
*/

int					main(int argc, char **argv)
{
	int				i;
	int				tmp;
	t_mdata_array	*array;
	
	i = 1;
	array = ft_arrayinit(100);
	if (argc == 1)
	{
		printf("Entrez des arguments a trier\n");
		exit(42);
	}
	while (i != argc)
	{
		tmp = ft_atoi(argv[i]);
		ft_arrayadd(array, ft_arraycreate(&tmp, sizeof(int)), 0);
		i++;
	}
	ft_arrayiter(array->start, array->nb_cases, print_array);
}
