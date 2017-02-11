#include "libft.h"

int				ft_strpos(char *str, char c)
{
	size_t		i;
	int			ret;

	i = 0;
	ret = -1;
	while(str[i])
	{
		if (str[i] == c)
		{
			ret = i;
			break;
		}
		i++;	
	}
	return (ret);
}
