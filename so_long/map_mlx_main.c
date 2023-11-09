/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mlx_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/01 16:02:49 by ccur              #+#    #+#             */
/*   Updated: 2023/11/01 16:02:49 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

int	object_image_up(t_game *g)
{
	int	x;
	int	y;

	g->floor_s = mlx_xpm_file_to_image(g->mlx, "./textures/ground.xpm", &x, &y);
	g->coin_s = mlx_xpm_file_to_image(g->mlx, "./textures/egg.xpm", &x, &y);
	g->wall_s = mlx_xpm_file_to_image(g->mlx, "./textures/wood.xpm", &x, &y);
	g->player_s = mlx_xpm_file_to_image(g->mlx, "./textures/chick.xpm", &x, &y);
	g->exit_s = mlx_xpm_file_to_image(g->mlx, "./textures/exit.xpm", &x, &y);
	if (g->floor_s == 0 || g->coin_s == 0 || g->wall_s == 0 || g->player_s == 0
		|| g->exit_s == 0)
		return (0);
	return (1);
}

void	object_put(char *str, t_game *game, int y)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '0')
			mlx_put_image_to_window(game->mlx, game->mlx_windows, game->floor_s,
				x * 32, y * 32);
		else if (str[x] == '1')
			mlx_put_image_to_window(game->mlx, game->mlx_windows, game->wall_s,
				x * 32, y * 32);
		else if (str[x] == 'C')
			mlx_put_image_to_window(game->mlx, game->mlx_windows, game->coin_s,
				x * 32, y * 32);
		else if (str[x] == 'P')
			mlx_put_image_to_window(game->mlx, game->mlx_windows, game->floor_s,
				x * 32, y * 32);
		else if (str[x] == 'E')
			mlx_put_image_to_window(game->mlx, game->mlx_windows, game->exit_s,
				x * 32, y * 32);
		x++;
	}
}

int	player_movement(int keycode, t_game *g)
{
	int	x;
	int	y;

	x = g->player_x;
	y = g->player_y;
	if (keycode == KEY_ESC)
		game_exit(g);
	else if (keycode == KEY_W && g->map[g->player_y - 1][g->player_x] != '1')
		g->player_y--;
	else if (keycode == KEY_S && g->map[g->player_y + 1][g->player_x] != '1')
		g->player_y++;
	else if (keycode == KEY_A && g->map[g->player_y][g->player_x - 1] != '1')
		g->player_x--;
	else if (keycode == KEY_D && g->map[g->player_y][g->player_x + 1] != '1')
		g->player_x++;
	if (x != g->player_x || y != g->player_y)
	{
		player_object_update(g);
		g->another++;
		return (ft_putnbr_fd(g->another, 1), ft_putstr_fd(". Number.\n", 1), 1);
	}
	return (1);
}

int	start_game(t_game *game)
{
	game->another = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->mlx_windows = mlx_new_window(game->mlx, game->map_w * 32, game->map_h
			* 32, "so_chicken");
	if (!game->mlx_windows)
		return (free(game->mlx), 0);
	if (object_image_up(game) == 0)
		return (0);
	mlx_key_hook(game->mlx_windows, player_movement, game);
	mlx_hook(game->mlx_windows, 17, 0L << 0, game_exit, game);
	mlx_loop_hook(game->mlx, map_update, game);
	mlx_loop(game->mlx);
	return (1);
}
