#include "libft.h"

void			ft_pqswap(t_array **start, size_t a, size_t b)
{
	t_array		*tmp;	
	
	tmp = start[a];
	start[a] = start[b];
	start[b] = tmp;
}
