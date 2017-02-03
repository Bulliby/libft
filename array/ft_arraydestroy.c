#include "libft.h"

void		free_elem_and_content(t_array *elem)
{
	free(elem->content);
	free(elem);
}

void			ft_arraydestroy(t_mdata_array *md)
{
	ft_arrayiter(md->start, md->nb_cases, free_elem_and_content);
	free(md->start);
	free(md);	
}
