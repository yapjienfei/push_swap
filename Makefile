NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = push_swap.c \
      op_rotate.c \
      op_reverse_rotate.c \
      op_swap_push.c \
      utils.c sort_utils.c sort_utils_2.c \
      get_target.c case_rotate.c \
      execute_case_rotations.c \
      parse.c

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