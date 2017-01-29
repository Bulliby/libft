# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwells <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/11 00:09:30 by gwells            #+#    #+#              #
#    Updated: 2016/11/25 14:13:14 by gwells           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

$(shell mkdir -p .obj/dlist/circ .obj/array .obj/is .obj/list .obj/malloc .obj/math\
.obj/mem .obj/pile .obj/pq .obj/printf .obj/put .obj/str .obj/utils 2> /dev/null)

SRC_DIRS	= $(shell find . -type d -follow -print)
SRC 		= $(shell find . ! -name  'main.c'  -type f -follow -print | grep -w "[.c]$$" | sed 's/^..//')
OBJ_PATH	= .obj/
OBJ_FILES	= $(SRC:.c=.o)
OBJ			= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

CC			= gcc 
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes

# **************************************************************************** #
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ) && ranlib $(NAME)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) a.out

re: fclean $(NAME)
