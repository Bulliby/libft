/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 14:29:28 by gwells            #+#    #+#             */
/*   Updated: 2018/02/12 21:38:10 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_tablen(char **ft_tab)
{
	int			ret;

	ret = 0;
	while (*ft_tab)
	{
		ret++;
		ft_tab++;
	}
	return (ret);
}

char			**ft_tabdup(char **tab)
{
	char		**tab2;
	int			i;
	int			len;

	if (tab)
	{
		i = 0;
		len = ft_tablen(tab);
		if (!(tab2 = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
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
