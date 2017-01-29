#include "libft.h"
#include <unistd.h>

static int		int_overflow(int nb, int neg, char str, void (*f)(void))
{
	nb *= 10;
	if ((neg > 0 && nb < 0) || (neg < 0 && (nb * neg) > 0))
		(*f)();
	nb += str - '0';
	if ((neg > 0 && nb < 0) || (neg < 0 && (nb * neg) > 0))
		(*f)();
	return (nb);
}

int		ft_atoi_protected(const char *str, void (*f)(void))
{
	int			nb;
	int			neg;

	nb = 0;
	neg = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nb = int_overflow(nb, neg, *str, f);
		str++;
	}
	if (*str)
		(*f)();
	return (nb * neg);
}
