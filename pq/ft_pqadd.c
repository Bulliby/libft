#include "libft.h"

static void		swap(t_mdata_pq *md, size_t index)
{
	if (index > 1 && md->cmp(md->start[index]->content, \
		md->start[index / 2]->content) <= 0)
	{
		ft_pqswap(md->start, index, index / 2);
		swap(md, index / 2);
	}
}

void			ft_pqadd(t_mdata_pq *md, t_array *elem)
{
	if (md->nb_cases && !(md->nb_cases % SIZE))
		ft_pqextend(md);
	md->start[md->nb_cases + 1] = elem;
	md->nb_cases++;
	swap(md, md->nb_cases);
}
