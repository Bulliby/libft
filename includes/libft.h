/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:15:02 by gwells            #+#    #+#             */
/*   Updated: 2016/12/07 13:00:04 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 100

# include <string.h>
# include <stdint.h>
# include <wchar.h>
# include "ft_printf.h"

typedef enum			e_bool
{
	false = 0,
	true
}						t_bool;

# include "malloc.h"

/*
**Pour C++
**#ifdef __cplusplus
**	 extern "C" {
**#endif
*/

/*
** array
*/

#define	SIZE 1024
#define ARRAY_DEFAULT_ALLOC SIZE * sizeof(t_array*)

typedef struct		s_array
{
	void			*content;
	size_t			content_size;
}					t_array;

typedef struct		s_mdata_array
{
	t_array			**start;
	size_t			nb_alloc;
	size_t			nb_cases;
}					t_mdata_array;

t_mdata_array		*ft_arrayinit(size_t nb_cases);
void				ft_arrayset(size_t index, t_mdata_array *md, t_array *ft_case);
t_array				*ft_arraycreate(void *content, size_t content_size); 
void				ft_arraysupress(t_mdata_array *md, size_t index,\
						void (*supress_func)(t_array **start, size_t nb_cases,\
							size_t index));
void				ft_unsorted_supress(t_array **start, size_t nb_cases, \
						size_t index);
void				ft_sorted_supress(t_array **start, size_t nb_cases,\
						size_t index);
void				ft_arrayiter(t_array **start, size_t nb_cases, \
						void (*f)(t_array *elem));
void				ft_arrayadd(t_mdata_array *md, t_array *elem, size_t index);
void				ft_arraydestroy(t_mdata_array *md);
void				ft_arrayextend(t_mdata_array *md);
void				ft_arraycontract(t_mdata_array *md);
void				free_elem_and_content(t_array *elem);
 
/*
** dlist
*/ 
typedef struct		s_dnode
{
	void			*content;
	size_t			content_size;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}					t_dnode;

typedef struct		s_dlist
{
	size_t			length;
	t_dnode			*head;
	t_dnode			*queue;
}					t_dlist;

t_dlist				*ft_dlstnew(void);
t_dnode				*ft_dlstnewnode(void const *content, size_t content_size);
t_dlist				*ft_dlstinsert(t_dlist *lst, t_dnode *newnode, size_t pos);
void				ft_dlstadd(t_dlist *lst, t_dnode *newnode);
void				ft_dlstdel(t_dnode **alst, void (*del)(void *, size_t));
void				ft_dlstpushback(t_dlist *list, t_dnode *newnode);
void				ft_dlstdelone(t_dnode **alst, void (*del)(void *, size_t));
void				ft_dlistrrotate(t_dlist *list);
void				ft_dlistrotate(t_dlist *lst);
t_dnode				*ft_dlistpop(t_dlist *lst);
t_dnode				*ft_dlistrpop(t_dlist *lst);
void				ft_dlistswap(t_dlist *lst);

/*
** dlist circ
*/
t_dnode				*ft_dlstnewnode_circ(void const *content,\
					size_t content_size, t_dlist *lst);
t_dlist				*ft_dlstnew_circ(t_dnode *head, t_dnode *queue);
void				ft_dlstadd_circ(t_dlist *lst, t_dnode *newnode);
void				ft_dlstpushback_circ(t_dlist *list, t_dnode *newnode);
void				ft_dlstsupress_at_circ(t_dlist *lst, t_dnode *to_supress,\
					void (*del)(void *, size_t));
void				ft_init_node_circ(t_dlist *lst, t_dnode *newnode);

/*
** is
*/
int					ft_isdigit(int c);
int					ft_isspace(const char c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/*
** list
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstinsert(t_list *head, t_list *newnode, size_t pos);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newnode);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t				ft_list_size(t_list *begin_list);
t_list				*ft_lstdup(int size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpushback(t_list **begin_list, t_list *newnode);

/*
** math
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_nbrlen_u(uintmax_t nbr);
int					ft_nbrlen(intmax_t nbr, int base);
int					ft_nbrline(int fd);
int					ft_atoi_protected(const char *str, void (*f)(void));
int					ft_abs(int i);

/*
** mem
*/
void				*ft_memalloc (size_t size);
void				ft_memdel (void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **app);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memalloc_fail(size_t size);
int					**ft_alloc_2d_int_tab(int x, int y);
char				**ft_tabdup(char **ft_tab);
void				ft_freetab(char **argv);

/*
** pile
*/
typedef struct		s_pile
{
	void			*content;
	size_t			content_size;
	struct s_pile	*prev;
}					t_pile;

t_pile				*ft_pilenew(void const *content, size_t content_size);
void				ft_pilepush(t_pile **pile, t_pile *newnode);
t_pile				*ft_pilepop(t_pile **pile);
void				ft_pileswap(t_pile **pile);
void				ft_pilerotate(t_pile **pile);
void				ft_pilerrotate(t_pile **pile);
size_t				ft_pilesize(t_pile *pile);
t_pile				*ft_piletail(t_pile *pile);

/*
** priority_queue
*/

/*
** put
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnchar(char c, int n);
void				ft_putnstr(char *str, int n);
void				ft_putnbrbase(uintmax_t nbr, char *base, size_t base_len);
void				ft_putnwstr(const wchar_t *str, size_t len);
void				ft_putwchar(wchar_t chr);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_printtab(char **argv);
void				ft_puthexa(void const *ptr, size_t size);

/*
** str
*/

size_t				ft_strlen (const char *str);
char				*ft_strdup (const char *str);
char				*ft_strcpy (char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat (char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void(*f)(char*));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_count_char(char *str, char c);
char				*ft_append_char(char *str, char c);
void				ft_strstriter(char **strstr, void (*f)(char *str));
char				*ft_strsupress_at(char *str, size_t pos);
char				*ft_strsupress_at(char *str, size_t pos);
char				*ft_strinsert_at(char *str, char c, size_t pos);
char				*ft_strpbrk(const char *s1, const char *s2);
char				*ft_strrpbrk(const char *s1, const char *s2);
int					ft_cntc(char *str, char c);
char				**ft_strsplit_ws(char const *s);

/*
** utils
*/
void				ft_bzero(void *str, size_t n);
char				*ft_union(char *argv);
int					get_next_line(int const fd, char **line);
size_t				words(char const *str, char c);
void				ft_quit(const char *error, int fd, int code);
int					ft_open_file(char *str, int flag);
void				ft_qsort(void *ft_tab, size_t nb_elem, size_t size_elem,\
					int(*diff)(void *const a, void *const b));
void				ft_isort(void *ft_tab, size_t nb_elem, size_t size_elem,\
					int(*diff)(void const *a, void const *b));
int					endofflag(int ac, char **argv);
char				*ft_getopt(int ac, char **argv, char *flags);

/*
** Pour C++
** #ifdef __cplusplus
**}
** #endif
*/
#endif
