/*Test of circ list*/

#include "libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char		str[42];

	memset(str, '\0', sizeof(str));
	strcpy(str, "toto est beau");
	ft_puthexa(str, sizeof(str));
}
