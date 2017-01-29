/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 11:43:24 by gwells            #+#    #+#             */
/*   Updated: 2016/06/02 19:56:15 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_FUNC_H
# define CONV_FUNC_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <wchar.h>

typedef struct		s_args
{
	int				hash;
	int				plus;
	int				minus;
	int				space;
	int				zero;
	int				width;
	int				preci;
	char			conv;
	int				got_preci;
	enum
	{
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				e_length;
}					t_args;

typedef struct		s_node
{
	char			*str;
	t_args			*opt;
	struct s_node	*next;
}					t_node;

typedef	void		(*t_func)(va_list *ap, t_node *node);

void				conv_int(va_list *ap, t_node *node);
void				conv_intl(va_list *ap, t_node *node);
void				pad_width(t_node *node, char *pref, int len, char c);
void				pad_preci(t_node *node, int len);
void				put_prefix(t_node *node, char *pref, int len, int conv);

void				conv_hexa(va_list *ap, t_node *node);
void				conv_octal(va_list *ap, t_node *node);
void				conv_octall(va_list *ap, t_node *node);

void				no_conv(va_list *ap, t_node *node, int pos);
void				conv_p(va_list *ap, t_node *node);
void				conv_unsigned(va_list *ap, t_node *node);
void				conv_unsignedl(va_list *ap, t_node *node);

void				conv_s(va_list *ap, t_node *node);
void				conv_wcharc(va_list *ap, t_node *node);
void				conv_char(va_list *ap, t_node *node);
void				c_pad_width(int len, t_node *node);

void				conv_wchar(va_list *ap, t_node *node);

int					is_conv(char c);
void				setup_ptrfunc(t_func *ptrfunc);
#endif
