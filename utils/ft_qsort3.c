#include "libft.h"
#include <stdlib.h>

static size_t 			cut_off(t_array *array, size_t lower, size_t upper)
{
	size_t				i;
	size_t				j;

	i = lower;
	j = lower;
	while (i != upper)
	{
		if (*(int*)array->data[i] < *(int*)array->data[upper])
		{
			ft_arrayswap(array, i, j);
			j++;
		}	
		i++;
	}	
	ft_arrayswap(array, upper, j);
	return (j);
}

void					ft_quicksort2(t_array *array, size_t lower, size_t upper)
{
	size_t	i_pivot;

	if (lower < upper)
	{
		i_pivot = cut_off(array, lower, upper);
		ft_quicksort2(array, lower, (!i_pivot) ? i_pivot : i_pivot - 1);
		ft_quicksort2(array, (i_pivot < upper) ?i_pivot + 1 : i_pivot, upper);
	}
}
