#include "libft.h"

static void		swap(t_pqata_pq *pq, size_t index)
{
	if (index > 1 && pq->cmp(pq->data[index]->content, \
		pq->data[index / 2]->content) <= 0)
	{
		ft_pqswap(pq->data, index, index / 2);
		swap(pq, index / 2);
	}
}

void			ft_pqadd(t_pq *pq, void *elem)
{
	if (pq->len && !(pq->len % SIZE))
		ft_arrayextend((t_pqata_array*)pq);
	pq->data[pq->len] = elem;
	pq->len++;
	swap(pq, pq->len - 1);
}
