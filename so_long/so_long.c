/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/10/27 02:53:47 by ccur              #+#    #+#             */
/*   Updated: 2023/11/01 16:21:34 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>

static void	zeroize_object(t_game *game)
{
	game->player = 0;
	game->coins = 0;
	game->exit = 0;
	game->another = 0;
}

static int	check(t_game *game, char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd <= 0)
		return (0);
	else if (check_filename(name) == 0)
		return (0);
	else if (fill_map(game, fd) == 0)
		return (0);
	else if (calculate_map(game) == 0)
		return (ft_free(game->map, (int)ft_sstrlen(game->map)), 0);
	else if (check_map_object(game) == 0)
		return (ft_free(game->map, (int)ft_sstrlen(game->map)), 0);
	else if (path_finder_main(game) == 0)
		return (ft_free(game->map, (int)ft_sstrlen(game->map)), 0);
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("EROR! Much argumant!\n", 1), 0);
	zeroize_object(&game);
	if (check(&game, av[1]) == 0)
		return (ft_putstr_fd("EROR! Incorrect file or content!\n", 1), 0);
	if (start_game(&game) == 0)
	{
		ft_putstr_fd("EROR! MLX EROR!!", 1);
		return (ft_free(game.map, (int)ft_sstrlen(game.map)), 0);
	}
	ft_free(game.map, game.map_h);
	return (0);
}
