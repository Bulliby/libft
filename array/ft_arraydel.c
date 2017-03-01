#include "libft.h"

void		ft_arraydel(t_array *array, size_t index)
{
	if (array->len > 1)
		ft_arrayswap(array, array->len - 1, index);
	array->len--;
}
