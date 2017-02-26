#include "libft.h"

void		ft_arraydel(t_array *array, size_t index)
{
	ft_arrayswap(array, array->len - 1, index);
	array->len--;
}
