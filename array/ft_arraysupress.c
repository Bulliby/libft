#include "libft.h"

/*
void				ft_arraysupress(t_mdata_array *md, size_t index,\
					void (*supress_func)(t_array **start, size_t nb_cases,
					size_t index))
{
	if (index < md->nb_cases)
	{
		if (md->nb_alloc * SIZE - md->nb_cases > SIZE + SIZE / 2)
			ft_arraycontract(md);
		(*supress_func)(md->start, md->nb_cases, index);
		md->nb_cases--;
	}
	else
		ft_putendl_fd("ft_arraysupress : read / write error with index", 2);
}
*/
