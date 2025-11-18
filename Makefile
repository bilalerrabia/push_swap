CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = healpers.c lst_tools.c stack_tools.c turck.c


NAME = push_swap



all: $(NAME)


$(NAME):
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

.PHONY: all clean fclean re