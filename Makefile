NAME = push_swap
CHECKER_NAME = checker
CC = gcc
SRC = push_swap.c node.c check_functions.c error.c utils1.c \
		free.c ft_atoi_extended.c swap1.c swap2.c swap3.c \
		sort_it.c big_sort.c big_sort2.c calc1.c calc2.c calc3.c biggest_three.c
CHECKER_SRC = checker.c checker_error.c checker_node.c checker_swap1.c \
		checker_swap2.c checker_swap3.c checker_utils.c checker_utils2.c checker_ft_atoi_extended.c

CSRC = $(addprefix my_checker/, $(CHECKER_SRC))

OBJ = $(SRC:.c=.o)
COBJ = $(CHECKER_SRC:.c=.o)
WFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(WFLAGS) -c $(SRC)
	@$(CC) $(WFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

bonus:
	@make -C libft
	@$(CC) $(WFLAGS) -c $(CSRC)
	@$(CC) $(WFLAGS) -o $(CHECKER_NAME) $(COBJ) $(LIBFT)

clean:
	@make -C libft
	@rm -f $(COBJ)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(CHECKER_NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus