CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap
NAME_BONUS = checker

SRC_PATH = srcs/
OBJ_PATH = objs/

SRC		= main.c \
		ft_split.c utils.c fill_stack.c error_handling.c \
		push_functions.c reverse_rotate_functions.c rotate_functions.c swap_functions.c \
		refresh.c sort_utils.c sorting.c tiny_sort.c

BONUS	= 	ft_split.c utils.c fill_stack.c error_handling.c \
			push_functions.c reverse_rotate_functions.c rotate_functions.c swap_functions.c \
			refresh.c sort_utils.c sorting.c tiny_sort.c \
			checker.c checker_utils.c get_next_line.c get_next_line_utils.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
BONUS_SRCS	= $(addprefix $(SRC_PATH), $(BONUS))
OBJ		= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
BONUS_OBJS	= $(addprefix $(OBJ_PATH), $(BONUS_OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(OBJ_PATH) $(NAME_BONUS)

.PHONY: all clean fclean re bonus