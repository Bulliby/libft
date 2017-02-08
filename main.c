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
	t_array			*array;
	int				toto;
	int				tata;

	array = ft_arrayinit(10);
	tata = 10;
	ft_arrayadd(array, &tata, 0);
	toto = 5;
	ft_arrayadd(array, &toto, 1);
	ft_arrayiter(array->data, array->len, print_array);
}
