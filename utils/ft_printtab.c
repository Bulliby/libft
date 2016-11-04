#include "../libft.h"

void		ft_printtab(char **argv)
{
	while (*argv)
	{
		ft_putendl(*argv);
		argv++;
	}
}
