#include "libft.h"

void				ft_arrayset(size_t index, t_mdata_array *md, t_array *ft_case)
{
	if (index < md->nb_cases)
	{
		free(md->start[index]);
		md->start[index] = ft_case;
	}
	else
		ft_putstr_fd("ft_arrayset : index makes write error", 2);
}
