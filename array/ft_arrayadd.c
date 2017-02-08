#include "libft.h"

void			ft_arrayadd(t_array *array, void *data, size_t index)
{
	void		*tmp;
	void		*tmp2;

	if (array->len && index > array->len)
		return ;
	if (!(array->len % SIZE))
		ft_arrayextend(array);
	tmp = array->data[index];
	array->data[index] = data;
	while (index < array->len)
	{
		tmp2 = array->data[index + 1];
		array->data[index + 1] = tmp;
		tmp = tmp2;
		index++;
	}
	array->len++;
}
