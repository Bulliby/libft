/*Test of circ list*/

#include "libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	*toto;

	if (argc <= 1)
		return (0);
	if ((toto = ft_getopt(argc, argv, "Ftu")) != NULL)
		printf("Il y est et c'est [%s]\n", toto);
	else
		printf("Il y est pas\n");
}
