#include "includes/libft.h"
#include <sys/time.h>

/*
static int				cmp(void *a, void *b)
{
	return (*(int*)b - *(int*)a);
}

*/
static void				print_array(void *elem)
{
	printf("[%i]", *(int*)elem);
}
int				main()
{
	size_t		i;
	t_array		*array;
	int			*values;
	
	i = 0;
	array = ft_arrayinit(101);
	values = ft_malloc_fail(101 * sizeof(int));	
	srand(time(NULL));
	while (i != 101)
	{
		values[i] = rand() % 100000;
		ft_arrayadd(array, &values[i], array->len);
		i++;
	}
	array->len = 101;
	printf("\nunsorted\n");
	ft_arrayiter(array->data, array->len, print_array);
	printf("\n");
	ft_quicksort2(array, 0, array->len - 1);
	printf("\nsorted\n");
	ft_arrayiter(array->data, array->len, print_array);
	return (0);
}
