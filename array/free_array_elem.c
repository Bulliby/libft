#include "libft.h"

void				free_array_elem(t_array *elem)
{
	free(elem->content);
	free(elem);
}
