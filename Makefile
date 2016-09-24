# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwells <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/11 00:09:30 by gwells            #+#    #+#              #
#    Updated: 2016/09/24 12:14:21 by gwells           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRC_DIRS	= $(shell find . -type d -follow -print)
SRC 		= $(shell find . ! -name  'main.c'  -type f -follow -print | grep -w "[.c]$$")
OBJ			= $(SRC:.c=.o)

CC			= gcc 
CFLAGS		= -Wall -Wextra -Werror

# **************************************************************************** #
$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ) && ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) a.out

re: fclean $(NAME)
