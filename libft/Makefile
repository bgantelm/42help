#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 15:03:09 by bgantelm          #+#    #+#              #
#    Updated: 2015/11/27 15:10:47 by bgantelm         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC= gcc
NAME= libft.a
SRC= *.c
OBJ= *.o
FLAGS= -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all