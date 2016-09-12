#include "../libft.h"

int		ft_tablen(char **tab)
{
	int len;

	len = 0;
	if (tab && *tab)
	{
		while (tab[len])
			len++;
		return (len);
	}
	return (0);
}
