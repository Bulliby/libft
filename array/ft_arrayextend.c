#include "libft.h"

void				ft_arrayextend(t_array *array, size_t index)
{
	void			**newdata;
	size_t			new_size;
	
	new_size = index * 2;
	newdata = ft_memalloc_fail(new_size * sizeof(void*));
	ft_memcpy(newdata, array->data, array->alloc);	
	array->alloc = new_size;
	free(array->data);
}
