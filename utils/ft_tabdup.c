#include "../libft.h"
#include <stdlib.h>

char	**ft_tabdup(char **tab)
{
	char	**tab2;
	int		i;
	int		len;

	if (tab)
	{
		i = 0;
		len = ft_tablen(tab);
		if (!(tab2 = (char **)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			tab2[i] = ft_strdup(tab[i]);
			i++;
		}
		tab2[i] = NULL;
		return (tab2);
	}
	return (NULL);
}
