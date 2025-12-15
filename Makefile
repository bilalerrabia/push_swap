CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = main.c parsing.c more_helpers.c push_swap_tools.c push_swap_tools2.c hitler_sort.c \
		ft_stalin_sort.c ft_stack_init.c ft_split.c ft_linked_list_tools.c ft_chunksort.c \
		sort_small.c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@echo "slak ajmi ma3ndi manmsa7"

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean