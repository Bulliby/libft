#include "libft.h"

void			ft_arrayadd(t_mdata_array *md, t_array *elem, size_t index)
{
	t_array		*tmp;
	t_array		*tmp2;

	if (index >= md->nb_cases + 1)
		return ;
	if (!(md->nb_cases % SIZE))
		ft_arrayextend(md);
	tmp = md->start[index];
	md->start[index] = elem;
	while (index < md->nb_cases)
	{
		tmp2 = md->start[index + 1];
		md->start[index + 1] = tmp;
		tmp = tmp2;
		index++;
	}
	md->nb_cases++;
}
