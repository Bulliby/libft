#include "../libft.h"

int			ft_cntc(char *str, char c)
{
	int		ret;

	ret = 0;	
	while (str && *str)
	{
		if (*str == c)
			ret++;
		str++;
	}
	return (ret);
}
