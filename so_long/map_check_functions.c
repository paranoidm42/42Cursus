/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:47:48 by ccur              #+#    #+#             */
/*   Updated: 2023/10/27 02:47:52 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_object(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (check_wall(game, game->map[i], i) == 0)
			return (0);
		else if (update_object(game, game->map[i], i) == 0)
			return (0);
		i++;
	}
	return (check_count_object(game));
}

int	check_count_object(t_game *game)
{
	if (game->player == 1 && game->coins >= 1 && game->exit == 1)
		return (1);
	return (0);
}

int	update_object(t_game *game, char *str, int y)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			game->player++;
			game->player_y = y;
			game->player_x = i;
		}
		else if (str[i] == 'E')
			game->exit++;
		else if (str[i] == 'C')
			game->coins++;
		else if (str[i] == '1' || str[i] == '0')
			game->another++;
		else
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_game *game, char *str, int index)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (index == 0 || index == game->map_h - 1)
		{
			if (str[i] != '1')
				return (0);
		}
		else
		{
			if (str[0] == '1' && str[game->map_w - 1] == '1')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}
