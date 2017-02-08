#include "includes/libft.h"

static void				print_array(void *elem)
{
	printf("[%i]", *(int*)elem);
}

static int				cmp_pq(void *a, void *b)
{
	return (*(int*)a - *(int*)b);
}

int					main(int argc, char **argv)
{
	t_pq			*pq;
	t_array			*array;
	int				*values;
	size_t			i;
	size_t			tmp;

	i = 0;
	pq = ft_pqinit(100000, cmp_pq);
	values = ft_memalloc_fail(100000 * sizeof(int));	
	while (i != 100000)
	{
		values[i] = rand() % 10000;
		ft_pqadd(pq, &(values[i]));
		i++;
	}
	ft_pqiter(pq->data, pq->len, print_array);
	array = ft_heapsort(pq);
	ft_arrayiter(array->data, array->len, print_array);
}
