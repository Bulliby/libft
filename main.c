#include "includes/libft.h"
#include <stdio.h>

void	error(void)
{
	ft_printf("error\n");
}	

int main(int argc, char **argv)
{
	(void)argc;
	printf("[%i]\n",  ft_atoi_protected(argv[1], error));
	ft_printf("[%i]\n",  ft_atoi_protected(argv[1], error));
	return (0);
}
