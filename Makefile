CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = healpers.c lst_tools.c stack_tools.c main.c ft_split.c stack_init.c \
		is_valid.c


NAME = push_swap



all: $(NAME)


$(NAME):
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)
# 	@echo "build"

clean:
	rm -f $(NAME)

fclean: clean

re : fclean all
.PHONY: all clean fclean re