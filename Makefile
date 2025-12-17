CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = main.c parsing.c more_helpers.c push_swap_tools.c push_swap_tools2.c hitler_sort.c \
		ft_stalin_sort.c ft_stack_init.c ft_split.c ft_linked_list_tools.c ft_chunksort.c \
		sort_small.c ihatenorm.c
OBJS = $(SRCS:.c=.o)
B_SRCS = bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c \
		bonus/main_bonus.c bonus/tester_bonus.c parsing.c more_helpers.c \
		push_swap_tools.c push_swap_tools2.c hitler_sort.c \
		ft_stalin_sort.c ft_stack_init.c ft_split.c ft_linked_list_tools.c \
		ft_chunksort.c sort_small.c ihatenorm.c
B_OBJS = $(B_SRCS:.c=.o)
B_NAME = checker
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
bonus: $(B_NAME) all

$(B_NAME): $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME)
clean:
	rm -f $(B_OBJS) $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean all

.PHONY: re all clean fclean bonus