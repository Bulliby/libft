#include "libft.h"

static void		free_array_elem(t_array *elem)
{
	free(elem);
}

void			ft_arraycontract(t_mdata_array *md)
{
	t_array		**new_start;		

	while (md->nb_alloc * SIZE - md->nb_cases > SIZE + SIZE / 2)
		md->nb_alloc--;
	//printf("nb_alloc [%zu]\n", md->nb_alloc);
	new_start = ft_memalloc_fail(md->nb_alloc * ARRAY_DEFAULT_ALLOC);
	ft_memcpy(new_start, md->start, md->nb_cases * sizeof(t_array*));
	free(md->start);
	md->start = new_start;
}
