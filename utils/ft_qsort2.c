#include "libft.h"
#include <stdlib.h>

static void				print_array(void *elem)
{
	printf("[%i]", *(int*)elem);
}

void		ft_quicksort(t_array *array, size_t lower, size_t upper)
{
	int		pivot;
	size_t	i;
	size_t	l_index;
	size_t	u_index;
	void	*tmp;
	size_t	i_pivot;
	t_bool	flag;

	l_index = lower;
	u_index = upper;
	i_pivot = upper / 2;
	if (i_pivot == lower)
		return;
	pivot = *(int*)array->data[i_pivot];
	i = 0;
	while (l_index < i_pivot && u_index > i_pivot)
	{
		flag = false;
		if (*(int*)array->data[l_index] > pivot)
		{
			tmp = array->data[u_index];
			array->data[u_index] = array->data[l_index];
			array->data[l_index] = tmp;
			flag = true;
		}
		if (*(int*)array->data[u_index] < pivot)
		{
			tmp = array->data[l_index];
			array->data[l_index] = array->data[u_index];	
			array->data[u_index] = tmp;
			flag = true;
		}
		if (flag == false)
		{
			l_index++;
			u_index--;
		}
		i++;
	}
	printf("\ni_pivot [%zu] PIVOT [%i]\n", i_pivot, pivot);
	ft_arrayiter(array->data, array->len, print_array);
	ft_quicksort(array, lower, i_pivot);
	ft_quicksort(array, i_pivot, upper);
}
