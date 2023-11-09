/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_dft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:52:15 by ccur              #+#    #+#             */
/*   Updated: 2023/11/02 22:03:11 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static int	is_within_bounds(t_game *swap, int y, int x)
{
	return (y >= 0 && y < swap->map_h && x >= 0 && x < swap->map_w);
}

static int	path_finder(t_game *swap, int y, int x)
{
	if (!is_within_bounds(swap, y, x) || swap->map[y][x] == '1'
		|| swap->map[y][x] == 'V')
		return (0);
	else if (swap->map[y][x] == 'C')
		swap->coins--;
	else if (swap->map[y][x] == 'E')
		swap->exit--;
	if (swap->exit == 0 && swap->coins == 0)
	{
		swap->map[y][x] = 'V';
		return (1);
	}
	swap->map[y][x] = 'V';
	path_finder(swap, y - 1, x);
	path_finder(swap, y + 1, x);
	path_finder(swap, y, x - 1);
	path_finder(swap, y, x + 1);
	return (1);
}

static int	swap_object_define(t_game *swap, t_game *game)
{
	int	i;

	i = 0;
	swap->map_h = game->map_h;
	swap->map_w = game->map_w;
	swap->coins = game->coins;
	swap->exit = game->exit;
	swap->map = malloc(sizeof(char *) * swap->map_h);
	if (!swap->map)
		return (0);
	while (i < swap->map_h)
	{
		swap->map[i] = malloc(sizeof(char) * swap->map_w);
		if (!swap->map[i])
			return (ft_free(swap->map, i), 0);
		ft_memcpy(swap->map[i], game->map[i], sizeof(char) * swap->map_w);
		i++;
	}
	return (1);
}

int	path_finder_main(t_game *game)
{
	t_game	swap;

	if (swap_object_define(&swap, game) == 0)
		return (0);
	path_finder(&swap, game->player_y, game->player_x);
	if (swap.coins != 0 || swap.exit != 0)
		return (ft_free(swap.map, game->map_h), 0);
	ft_free(swap.map, game->map_h);
	return (1);
}
