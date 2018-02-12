/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:15:30 by gwells            #+#    #+#             */
/*   Updated: 2018/02/12 21:39:25 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <sys/time.h>

void						ft_printtime(t_bool start)
{
	static struct timeval	t1;
	struct timeval			t2;
	double					ret;

	if (start)
	{
		ft_bzero(&t1, sizeof(struct timeval));
		if (gettimeofday(&t1, NULL) == -1)
			exit(42);
		ft_printf("Vous lancez le programme\n");
	}
	else
	{
		ft_bzero(&t2, sizeof(struct timeval));
		if (gettimeofday(&t2, NULL) == -1)
			exit(42);
		ret = (t2.tv_sec - t1.tv_sec) + \
		((t2.tv_usec - t1.tv_usec) / 1000000.0);
		ft_printf("Il y a [%lf] secondes que vous avez\
		lance le programe\n", ret);
	}
}
