/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:12:31 by gwells            #+#    #+#             */
/*   Updated: 2016/06/11 20:25:44 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(void)
{
	char	*test;
	char	*str;

	str = ft_strdup("\t ");
	test = ft_strdup("totoest le meilleur");

	printf("voici la chaine [%s]\n", ft_strpbrk(test, str));
}
