#include "libft.h"

t_mdata_pq			*ft_pqinit(size_t nb_cases, int (*cmp)(void *, void *))
{
	t_mdata_pq		*md;

	md = ft_memalloc_fail(sizeof(t_mdata_pq));
	md->nb_alloc = nb_cases / SIZE + 1;
	md->start = ft_memalloc_fail(md->nb_alloc * ARRAY_DEFAULT_ALLOC);
	md->nb_cases = 0;
	md->cmp = (*cmp);
	return (md);
}
