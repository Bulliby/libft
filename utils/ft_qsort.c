#include "libft.h"
#include <stdlib.h>

static size_t 			cut_off(t_array *array, const size_t lower, size_t upper,\
						int (*cmp)(void const * a, void const *b))
{
	size_t				i;
	size_t				j;

	i = lower;
	j = lower;
	while (i != upper)
	{
		if (cmp(array->data[i], array->data[upper]) > 0)
		{
			ft_arrayswap(array, i, j);
			j++;
		}	
		i++;
	}	
	ft_arrayswap(array, upper, j);
	return (j);
}

void					ft_quicksort(t_array *array, size_t lower, size_t upper, \
						int (*cmp)(void const * a, void const *b))
{
	size_t	i_pivot;

	if (lower < upper)
	{
		i_pivot = cut_off(array, lower, upper, cmp);
		ft_quicksort(array, lower, (!i_pivot) ? i_pivot : i_pivot - 1, cmp);
		ft_quicksort(array, (i_pivot < upper) ?i_pivot + 1 : i_pivot, upper, cmp);
	}
}
