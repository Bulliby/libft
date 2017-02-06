#include "libft.h"

void			ft_pqextend(t_mdata_pq *md)
{
	t_array			**new_start;

	printf("extend\n");
	if (md->nb_cases && !(md->nb_cases % SIZE))
	{
		md->nb_alloc++;
		new_start = ft_memalloc_fail(md->nb_alloc * ARRAY_DEFAULT_ALLOC);
		ft_memcpy(new_start, md->start, (md->nb_alloc - 1) * ARRAY_DEFAULT_ALLOC);
		free(md->start);
		md->start = new_start;
	}
}
