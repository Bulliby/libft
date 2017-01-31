#include "libft.h"

void			ft_arraydestroy(t_mdata_array *md)
{
	ft_arrayiter(md->start, md->nb_cases, free_array_elem);
	free(md->start);
	free(md);	
}
