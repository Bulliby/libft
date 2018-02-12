/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 20:21:54 by gwells            #+#    #+#             */
/*   Updated: 2018/02/12 21:37:34 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			isflag(int pos, char **argv)
{
	if (pos > 1)
	{
		if (argv[pos][0] == '-' && argv[pos][1] != '\0')
			return (isflag(pos - 1, argv));
	}
	else
	{
		if (argv[pos][0] == '-' && argv[pos][1] != '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

int					endofflag(int ac, char **argv)
{
	int			i;

	i = 1;
	while (i < ac && isflag(i, argv))
	{
		if (!ft_strcmp(argv[i], "--"))
			return (i + 1);
		i++;
	}
	return (i);
}

static char			*flagtochar(char *argv)
{
	static char		*str = NULL;
	char			*temp;
	char			*temp2;

	temp = NULL;
	temp2 = NULL;
	if (str != NULL)
	{
		temp = ft_strdup(str);
		ft_strdel(&str);
	}
	if (argv)
		temp2 = ft_strjoin(temp, argv + 1);
	else
		temp2 = ft_strjoin(temp, argv);
	str = ft_strdup(temp2);
	ft_strdel(&temp);
	ft_strdel(&temp2);
	return (str);
}

static int			trueflag(char *argv, char *flags)
{
	int				test;
	int				i;

	flagtochar(argv);
	if (*argv != '-')
		return (0);
	argv++;
	while (*argv)
	{
		i = 0;
		test = 0;
		while (flags[i])
		{
			if (flags[i] == *argv)
				test = 1;
			i++;
		}
		if (!test)
			return (0);
		argv++;
	}
	return (1);
}

char				*ft_getopt(int argc, char **argv, char *flags)
{
	int				end;
	int				i;

	i = 1;
	end = endofflag(argc, argv);
	if (!ft_strcmp(argv[end - 1], "--"))
		end--;
	if (end <= i)
		return (ft_strdup(""));
	while (i != end)
	{
		if (!trueflag(argv[i], flags))
			return (NULL);
		i++;
	}
	return (flagtochar(NULL));
}
