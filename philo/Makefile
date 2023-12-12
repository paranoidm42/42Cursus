NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

SRCS = main.c thread_utils.c thread.c utils.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
