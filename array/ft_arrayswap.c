#include "libft.h"

void		ft_arrayswap(t_array *array, size_t a, size_t b)
{
	void	*tmp;

	tmp = array->data[a];
	array->data[a] = array->data[b];
	array->data[b] = tmp;
}
