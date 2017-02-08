#include "includes/libft.h"

static void				print_array(void *elem)
{
	printf("[%i]", *(int*)elem);
}

static int				cmp(void *a, void *b)
{
	return (*(int*)b - *(int*)a);
}

static size_t		select_max(void **data, const size_t len)
{
	size_t			ret;
	void			*limit;
	size_t			i;
	
	i = 0;
	limit = data[0];
	ret = 0;
	while (i != len)
	{
		if (*(int*)data[i] > *(int*)limit)
		{
			limit = data[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

static size_t		select_min(void **data, size_t len)
{
	size_t			ret;
	void			*limit;
	size_t			i;
	
	i = 0;
	limit = data[0];
	ret = 0;
	while (i != len)
	{
		if (*(int*)data[i] < *(int*)limit)
		{
			limit = data[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}


int					main(int argc, char **argv)
{
	t_pq			*pq;
	t_array			*array;
	int				*values;
	size_t			i;
	size_t			tmp;

	i = 0;
	pq = ft_pqinit(100000, cmp);
	array = ft_arrayinit(100000);
	values = ft_memalloc_fail(100000 * sizeof(int));	
	srand(time(NULL));
	while (i != 100000)
	{
		values[i] = rand() % 10000;
		//ft_arrayadd(array, &(values[i]), array->len);
		ft_pqadd(pq, &values[i]);
		i++;
	}
	//ft_pqiter(pq->data, pq->len, print_array);
	//array = ft_selectsort(array, select_max);
	array = ft_heapsort(pq);
	//ft_arrayiter(array->data, array->len, print_array);
}
