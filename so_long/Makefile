NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = map_check_functions.c map_functions.c \
	map_mlx_hook.c map_mlx_main.c \
	path_finder_dft.c so_long.c


MLXDIR = ./minilibx
MLXFLAGS = -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit


LIBFTDIR = ./libft
LIBFTA = ./libft/libft.a

all: $(NAME)

$(NAME):
	@make -C $(MLXDIR)
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) $(SRC) $(LIBFTA) $(MLXFLAGS) -o $(NAME)

clean:
	@make -C $(LIBFTDIR) clean
	@make -C $(MLXDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(MLXDIR) clean

re: fclean all

.PHONY: all clean fclean re
