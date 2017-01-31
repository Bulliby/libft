#include "libft.h"

void			ft_arraycontract(t_mdata_array *md)
{
	t_array		**new_start;		

	md->nb_alloc--;
	new_start = ft_memalloc_fail(md->nb_alloc * ARRAY_DEFAULT_ALLOC);
	ft_memcpy(new_start, md->start, md->nb_cases * sizeof(t_array));
	ft_arrayiter(md->start, md->nb_cases, free_array_elem);
	free(md->start);
	md->start = new_start;
}
