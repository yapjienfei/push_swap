NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c operations_reverse_rotate.c operations_swap_push.c utils.c utils_2.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re