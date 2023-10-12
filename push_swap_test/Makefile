SRCS	= push_swap.c ft_atoi_long.c check_func_two.c check_func.c\
sort_two.c sort.c swapers_two.c swapers.c utils_sort.c
OBJS	= $(SRCS:.c=.o)

LIBFT_PATH	= libft/
LIBFT		= $(LIBFT_PATH)libft.a

CFLAGS	= -Wall -Werror -Wextra

NAME	= push_swap

RM		= rm -f

GC		= gcc -g

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(GC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(GC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
