/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:50:27 by ccur              #+#    #+#             */
/*   Updated: 2023/11/09 16:06:39 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "so_long.h"

int	check_filename(char *str)
{
	int	len;

	len = (int)ft_strlen(str);
	if (len >= 4 && ft_strncmp(str + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	fill_map(t_game *game, int fd)
{
	char	*line;
	char	*swap;

	line = get_next_line(fd);
	if (!line)
		return (0);
	game->map_swap = ft_strdup(line);
	free(line);
	if (!game->map_swap)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\0')
			break ;
		if (ft_strlen(line) < 4)
			return (free(line), free(game->map_swap), 0);
		swap = ft_strjoin(game->map_swap, line);
		free(line);
		if (!swap)
			return (free(game->map_swap), 0);
		free(game->map_swap);
		game->map_swap = swap;
	}
	return (free(line), 1);
}

int	calculate_map(t_game *game)
{
	game->map = ft_split(game->map_swap, '\n');
	if (!game->map)
		return (free(game->map_swap), 0);
	free(game->map_swap);
	game->map_h = ft_sstrlen(game->map);
	game->map_w = (int)ft_strlen(game->map[0]);
	return (check_map_size(game));
}

int	check_map_size(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	if (game->map_h == 1 || game->map_w == 1 || game->map_w == game->map_h)
		return (0);
	while (game->map[i])
	{
		len = (int)ft_strlen(game->map[i]);
		if (game->map_w != len)
			return (0);
		i++;
	}
	return (1);
}
