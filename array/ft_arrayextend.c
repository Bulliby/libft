#include "libft.h"

void				ft_arrayextend(t_array *array)
{
	void			*newdata;

	if (!(array->len % SIZE))
	{
		array->alloc++;
		newdata = ft_memalloc_fail(array->alloc * ARRAY_DEFAULT_ALLOC);
		ft_memcpy(newdata, array->data, (array->alloc - 1) * ARRAY_DEFAULT_ALLOC);
		free(array->data);
		array->data = newdata;
	}
}
