#include "libft.h"

void			ft_arrayiter(t_array **start, size_t nb_cases,\
				void (*f)(t_array *elem))
{
	size_t		i;

	i = 0;
	while (i != nb_cases)
	{
		(*f)(start[i]);
		i++;
	}	
}
