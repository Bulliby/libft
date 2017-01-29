/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:43:46 by gwells            #+#    #+#             */
/*   Updated: 2015/05/16 13:25:12 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "conv_func.h"

int			ft_printf(char *format, ...);

uintmax_t	get_unsigned(va_list *ap, t_node *node);
intmax_t	get_signed(va_list *ap, t_node *node);

void		split(char *format, t_node **begin);

void		print_lst(t_node *begin);
void		pushback(t_node **begin, t_node *new);
t_node		*new_elem(char *str);

void		parsing(t_node *begin, va_list *ap);

void		print_wchar(wchar_t chara);
int			wcharlen(wchar_t *str, int type);
int			wcharnlen(wchar_t *str, int n);
void		putswchar(wchar_t *str);
void		putsnwchar(wchar_t *str, int n);
int			wchar_real_len(wchar_t c);

int			printf_putnchar(char c, int n);
void		putnstr(char *str, int n);
void		ft_putnbrbase(uintmax_t nbr, char *base, size_t base_len);
void		putstr(char *str);
#endif
