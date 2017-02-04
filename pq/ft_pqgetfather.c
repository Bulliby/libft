#include "libft.h"

t_array				*ft_pqgetfather(t_array **start, size_t child_index)
{
	return (start[child_index / 2]);	
}
