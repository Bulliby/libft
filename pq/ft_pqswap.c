#include "libft.h"

void			ft_pqswap(void **data, size_t a, size_t b)
{
	void		*tmp;	
	
	tmp = data[a];
	data[a] = data[b];
	data[b] = tmp;
}
