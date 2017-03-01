/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwells <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 10:42:35 by gwells            #+#    #+#             */
/*   Updated: 2017/03/01 11:02:49 by gwells           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <string.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# define TINY_BLOCK 512 * getpagesize()
# define SMALL_BLOCK 4096 * getpagesize()
# define TINY_LIMIT 992
# define SMALL_LIMIT 7936

typedef enum			e_bool
{
	false = 0,
	true
}						t_bool;

typedef enum			e_size
{
	TINY = 0,
	SMALL,
	LARGE
}						t_size;

typedef struct			s_block
{
	t_bool				free;
	size_t				size;
	char				*addr;
	struct s_block		*next;
}						t_block;

typedef struct			s_mem
{
	char				*block_start[3];
	char				*current_block[3];
	char				*end_of_block[3];
}						t_mem;

/*
** malloc.c
*/
void					*ft_malloc(size_t size);

/*
** stock.c
*/
void					*init_all_stock(t_mem *block_start);
void					*add_large_stock(t_mem *s, size_t size);
void					re_populate_stock(t_mem *blocks, t_size area);

/*
** list.c
*/
void					iter_block(t_size area, \
	void (*f)(t_block *tmp, size_t size));
void					*choose_alloc(t_mem *s, size_t size);
void					*add_block(t_mem *blocks, t_size area, size_t size);

/*
** show_alloc_mem.c
*/
void					show_alloc_mem();

/*
** singleton.c
*/
t_mem					*singleton(void);

/*
** free.c
*/
void					ft_free(void *ptr);
void					*check_for_free(t_mem *blocks, \
	t_size area, size_t size);

/*
** realloc.c
*/
void					*ft_realloc(void *ptr, size_t size);
t_size					in_range(t_mem *blocks, char *ptr);
t_bool					is_allocated(t_block *start, char *ptr);

/*
** print.c
*/
void					conv_p_malloc(intmax_t adress);

/*
** calloc.c
*/
void					*ft_calloc(size_t count, size_t size);
#endif
