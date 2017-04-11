NAME		= 	libft.a

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	= 	-I./includes
SRC_ARRAY	= 	./array/
SRC_IS		=	./is/
SRC_LIST	=	./list/
SRC_DLIST	=	./dlist/
SRC_DLISTC	=	./dlist/circ/
SRC_MALLOC	=	./malloc/
SRC_MATH	=	./math/
SRC_MEM		=	./mem/
SRC_PILE	=	./pile/
SRC_PQ		=	./pq/
SRC_PRINTF	=	./printf/
SRC_PUT		=	./put/
SRC_STR		=	./str/
SRC_UTILS	=	./utils/

$(shell mkdir .obj 2> /dev/null)

OBJ_UTILS 	= 	ft_alloc_2d_int.o\
				ft_bzero.o\
				ft_freetab.o\
				ft_getopt.o\
				ft_heapsort.o\
				ft_open_file.o\
				ft_printtab.o\
				ft_qsort.o\
				ft_quit.o\
				ft_tabdup.o\
				ft_union.o\
				get_next_line.o\
				ft_selectsort.o\
				ft_printtime.o\
				ft_qsort.o\
				ft_pow.o\

OBJ_ARRAY	=	ft_arrayadd.o\
				ft_arrayextend.o\
				ft_arrayinit.o\
				ft_arrayiter.o\
				ft_arrayswap.o\
				ft_arraydel.o\

OBJ_DLIST	=	ft_dlistpop.o\
				ft_dlistrotate.o\
				ft_dlistrpop.o\
				ft_dlistrrotate.o\
				ft_dlistswap.o\
				ft_dlstadd.o\
				ft_dlstdel.o\
				ft_dlstdelone.o\
				ft_dlstinsert.o\
				ft_dlstnew.o\
				ft_dlstnewnode.o\
				ft_dlstpushback.o\

OBJ_DLISTC	=	ft_dlist_init_circ.o\
				ft_dlstadd_circ.o\
				ft_dlstnew_circ.o\
				ft_dlstnewnode_circ.o\
				ft_dlstpushback_circ.o\
				ft_dlstsupress_at_circ.o\

OBJ_IS		=	ft_isalnum.o\
				ft_isalpha.o\
				ft_isascii.o\
				ft_isdigit.o\
				ft_islower.o\
				ft_isort.o\
				ft_isprint.o\
				ft_isspace.o\
				ft_isupper.o\

OBJ_LIST	=	ft_list_size.o\
				ft_lstadd.o\
				ft_lstdel.o\
				ft_lstdelone.o\
				ft_lstempty.o\
				ft_lstinsert.o\
				ft_lstiter.o\
				ft_lstmap.o\
				ft_lstnew.o\
				ft_lstpushback.o\

OBJ_MALLOC	=	calloc.o\
				free.o\
				malloc_list.o\
				malloc.o\
				malloc_print.o\
				realloc.o\
				show_alloc_mem.o\
				singleton.o\
				stock.o\

OBJ_MATH	=	ft_abs.o\
				ft_atoi.o\
				ft_atoi_protected.o\
				ft_itoa.o\
				ft_nbrlen.o\
				ft_nbrlen_u.o\
				ft_nbrline.o\
				ft_tablen.o\

OBJ_MEM		=	ft_malloc_fail.o\
				ft_memalloc.o\
				ft_memalloc_fail.o\
				ft_memccpy.o\
				ft_memchr.o\
				ft_memcmp.o\
				ft_memcpy.o\
				ft_memdel.o\
				ft_memmove.o\
				ft_memset.o\

OBJ_PILE	=	ft_pilenew.o\
				ft_pilepop.o\
				ft_pilepush.o\
				ft_pilerotate.o\
				ft_pilerrotate.o\
				ft_pilesize.o\
				ft_pileswap.o\
				ft_piletail.o\
				ft_mergesort.o\
				ft_pileiter.o\
				ft_pilepushback.o\

OBJ_PQ		= 	ft_pqadd.o\
				ft_pqinit.o\
				ft_pqiter.o\
				ft_pqswap.o\
				ft_pqsupress.o\

OBJ_PRINTF	=	conv_gen.o\
				conv_ooxx.o\
				conv_s.o\
				conv_scc.o\
				conv_uunop.o\
				ft_printf.o\
				get_number.o\
				list.o\
				parsing.o\
				print.o\
				print_wchar.o\
				ptrfunc.o\
				split.o\

OBJ_PUT		=	ft_putchar.o\
				ft_putchar_fd.o\
				ft_putendl.o\
				ft_putendl_fd.o\
				ft_puthexa.o\
				ft_putnbr.o\
				ft_putnbr_fd.o\
				ft_putnbrbase.o\
				ft_putnchar.o\
				ft_putnstr.o\
				ft_putstr.o\
				ft_putstr_fd.o\
				ft_putwchar.o\
				ft_putwchar_fd.o\
				ft_putwstr.o\

OBJ_STR		=	ft_append_char.o\
				ft_cntc.o\
				ft_count_char.o\
				ft_strcat.o\
				ft_strchr.o\
				ft_strclr.o\
				ft_strcmp.o\
				ft_strcpy.o\
				ft_strdel.o\
				ft_strdup.o\
				ft_strequ.o\
				ft_strinsert_at.o\
				ft_striter.o\
				ft_striteri.o\
				ft_strjoin.o\
				ft_strlcat.o\
				ft_strlen.o\
				ft_strmap.o\
				ft_strmapi.o\
				ft_strncat.o\
				ft_strncmp.o\
				ft_strncpy.o\
				ft_strnequ.o\
				ft_strnew.o\
				ft_strnstr.o\
				ft_strpbrk.o\
				ft_strrchr.o\
				ft_strrpbrk.o\
				ft_strsplit.o\
				ft_strsplit_ws.o\
				ft_strstr.o\
				ft_strstriter.o\
				ft_strsub.o\
				ft_strsupress_at.o\
				ft_strtrim.o\
				ft_tolower.o\
				ft_toupper.o\
				words.o\
				ft_strpos.o\

OBJ_PATH	=	.obj/
OBJS		=	$(OBJ_UTILS) $(OBJ_ARRAY) $(OBJ_DLIST) $(OBJ_DLISTC) $(OBJ_IS)\
		  		$(OBJ_MATH) $(OBJ_PRINTF) $(OBJ_MEM) $(OBJ_MALLOC) $(OBJ_STR)\
		  		$(OBJ_PUT) $(OBJ_PILE) $(OBJ_MATH) $(OBJ_LIST) $(OBJ_PQ)

COMPILE		=	$(addprefix $(OBJ_PATH), $(OBJS))

all: $(NAME)

$(NAME): $(COMPILE)
	ar -rc $(NAME) $(COMPILE) && ranlib $(NAME)

clean:
	rm -rf $(COMPILE)

fclean: clean
	rm -rf $(NAME) a.out

re: fclean $(NAME)

$(OBJ_PATH)%.o: $(SRC_PUT)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_STR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_DLIST)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_MEM)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_MALLOC)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PRINTF)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_DLISTC)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	
$(OBJ_PATH)%.o: $(SRC_PILE)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_MATH)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_IS)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_LIST)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PQ)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_UTILS)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_ARRAY)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
