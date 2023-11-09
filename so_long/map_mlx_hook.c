/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mlx_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:48:13 by ccur              #+#    #+#             */
/*   Updated: 2023/11/02 22:03:23 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include "so_long.h"

int	map_update(t_game *game)
{
	int	y;

	y = 0;
	mlx_clear_window(game->mlx, game->mlx_windows);
	while (game->map[y])
	{
		object_put(game->map[y], game, y);
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_windows, game->player_s,
		game->player_x * 32, game->player_y * 32);
	return (1);
}

int	game_exit(t_game *game)
{
	ft_free(game->map, game->map_h);
	mlx_destroy_image(game->mlx, game->coin_s);
	mlx_destroy_image(game->mlx, game->player_s);
	mlx_destroy_image(game->mlx, game->wall_s);
	mlx_destroy_image(game->mlx, game->exit_s);
	mlx_destroy_image(game->mlx, game->floor_s);
	mlx_destroy_window(game->mlx, game->mlx_windows);
	exit(0);
}

void	player_object_update(t_game *game)
{
	if (game->coins == 0 && game->map[game->player_y][game->player_x] == 'E')
		game_exit(game);
	else if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->coins--;
		game->map[game->player_y][game->player_x] = '0';
	}
}
