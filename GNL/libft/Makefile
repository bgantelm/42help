SRCS = *.c
OBJECTS = *.o
NAME = libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	@gcc $(FLAGS) -I /includes/ -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Libft :\033[1;33m DONE !\033[m"
clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

test :

re : fclean all
