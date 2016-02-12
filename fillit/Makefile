# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glangloi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/11 16:30:59 by glangloi          #+#    #+#              #
#    Updated: 2016/02/11 16:50:33 by glangloi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/main.c\

OBJ = $(SRCS:.c=.o)

INC = inc/fillit.h\

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
