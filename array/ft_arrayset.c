#include "libft.h"

void				ft_arrayset(t_array *array, size_t index, void *data)
{
	if (index >= array->alloc)
		ft_arrayextend(array, index);
	if (index >= array->len)
		array->len = index + 1;
	array->data[index] = data;
}
