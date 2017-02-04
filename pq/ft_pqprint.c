#include "libft.h"

static size_t		get_index_childl(size_t index)
{
	return (index * 2);
}

static size_t		get_index_childr(size_t index)
{
	return (index * 2 + 1);
}

static size_t		get_father_index(size_t index)
{
	return (index / 2);
}

void				ft_pqprint(t_mdata_pq *md, size_t index)
{
	
}
