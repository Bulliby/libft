/*Test of circ list*/

#include "libft.h"
#include <stdio.h>

int		diff(void * const a, void * const b)
{
	if (ft_strcmp(a , b) > 0)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i != argc)
	{
		ft_qsort(*argv, argc -1, sizeof(char*), &diff);
		ft_printtab(argv);
		i++;
	}
}
