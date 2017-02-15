#include "includes/libft.h"
#include <sys/time.h>

static int				cmp(void const *a, void const *b)
{
	return (*(int*)b - *(int*)a);
}

/*
static void				print_array(void *elem)
{
	printf("[%i]", *(int*)elem);
}

*/
int				main()
{
	size_t		i;
	t_array		*array;
	int			*values;
	
	i = 0;
	array = ft_arrayinit(1000000);
	values = ft_malloc_fail(1000000 * sizeof(int));	
	srand(time(NULL));
	while (i != 1000000)
	{
		values[i] = rand() % 1000000;
		ft_arrayadd(array, &values[i], array->len);
		i++;
	}
	array->len = 1000000;
	ft_quicksort2(array, 0, array->len - 1, cmp);
	return (0);
}

/*
int				main(int argc, char **argv)
{
	int			*values;
	t_array		*array;

	if (argc < 2)
	{
		printf("Veuillez entrer un nombre\n");
		exit(EXIT_FAILURE);
	}
	values = ft_malloc_fail(sizeof(int) * (argc - 1));
	array = ft_arrayinit(argc - 1);
	while (argc > 1)
	{
		values[argc - 2] = ft_atoi(argv[argc - 1]);
		ft_arrayadd(array, &values[argc - 2], array->len);
		argc--;	
	}
	ft_quicksort2(array, 0, array->len - 1, cmp);
	ft_arrayiter(array->data, array->len, print_array);
}
*/
