#include "../libft.h"
#include <stdlib.h>

static int		ft_array_size(char const *s)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (*s)
	{
		if (i == 1 && (*s == ' ' || *s == '\t'))
			i = 0;
		if (i == 0 && *s != ' ' && *s != '\t')
		{
			i = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		ft_word_len(char const *s)
{
	int		len;

	len = 0;
	while (*s && *s != ' ' && *s != '\t')
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strsplit_ws(char const *s)
{
	int		i;
	int		nb_word;
	char	**tab;

	i = 0;
	nb_word = ft_array_size(s);
	tab = (char **)malloc(sizeof(char *) * ((ft_array_size(s)) + 1));
	if (tab == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		tab[i] = ft_strsub((const char *)s, 0, ft_word_len(s));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_word_len(s);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
