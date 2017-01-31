#include "libft.h"

void			ft_sorted_supress(t_array **start, size_t nb_cases,\
			size_t index)
{
	free(start[index]->content);
	free(start[index]);
	while  (index != nb_cases)
	{
		start[index] = start[index + 1];
		index++;
	}
}
