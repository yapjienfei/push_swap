NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = push_swap.c \
      operations_rotate.c \
      operations_reverse_rotate.c \
      operations_swap_push.c \
      utils.c utils2.c utils3.c \
      sort.c sort2.c sort3.c sort4.c sort5.c sort6.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re