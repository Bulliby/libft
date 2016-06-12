/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:12:31 by gwells            #+#    #+#             */
/*   Updated: 2016/06/12 13:19:10 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	char	*test;
	char	*str;
	char	*pos;

	str = ft_strdup("\t ");
	test = ft_strdup("toto est le meilleur titi");
	pos = ft_strrpbrk(test, str);
	printf("voici la chaine [%s]\n", pos);
	pos = ft_strrpbrk(pos, str);
	printf("voici la chaine [%s]\n", pos);
}
