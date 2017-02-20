#include "libft.h"

void			ft_pileiter(t_pile *pile, void (*f)(t_pile *elem))
{
	while (pile)
	{
		(*f)(pile);
		pile = pile->prev;
	}
}
