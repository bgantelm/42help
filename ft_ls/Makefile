#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 11:50:00 by bgantelm          #+#    #+#              #
#    Updated: 2015/12/10 11:50:05 by bgantelm         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
LIB_NAME = libft/libft.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR)
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
LIBFLAGS = -Llibft -lft
RM = /bin/rm -f

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	@make -C libft re

$(NAME) : $(OBJS)
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@$(CC) $(LIBFLAGS) -o $@ $^
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@make -C libft clean
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re
