#include "libft.h"

void			*ft_malloc_fail(size_t size)
{
	void		*mem;

	if (!(mem = malloc(size)))
		ft_quit("Malloc failed", 2, EXIT_FAILURE);
	return (mem);
}
