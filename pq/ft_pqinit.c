#include "libft.h"

t_pq			*ft_pqinit(size_t len, int (*cmp)(void *, void *))
{
	t_pq		*pq;

	pq = ft_memalloc_fail(sizeof(t_pq));
	pq->alloc = len / SIZE + 1;
	pq->data = ft_memalloc_fail(pq->alloc * ARRAY_DEFAULT_ALLOC);
	pq->len = 1;
	pq->cmp = (*cmp);
	return (pq);
}
