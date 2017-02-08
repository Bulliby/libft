#include "libft.h"

void			ft_pqiter(void **data, size_t nb_cases,\
				void (*f)(void *elem))
{
	size_t		i;

	i = 1;
	while (i != nb_cases)
	{
		(*f)(data[i]);
		i++;
	}	
}
