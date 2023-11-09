/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 02:54:30 by ccur              #+#    #+#             */
/*   Updated: 2023/11/02 22:38:34 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct f_game
{
	char	*map_swap;
	char	**map;
	int		map_h;
	int		map_w;

	void	*mlx;
	void	*mlx_windows;

	void	*player_s;
	void	*wall_s;
	void	*exit_s;
	void	*coin_s;
	void	*floor_s;

	int		player_x;
	int		player_y;

	int		player;
	int		coins;
	int		exit;
	int		another;

}			t_game;

int			fill_map(t_game *game, int fd);
int			calculate_map(t_game *game);
int			check_filename(char *str);
int			check_map_size(t_game *game);
int			check_map_object(t_game *game);
int			update_object(t_game *game, char *str, int y);
int			check_count_object(t_game *game);
int			check_wall(t_game *game, char *str, int index);
int			path_finder_main(t_game *game);
int			ft_sstrlen(char **s);

int			object_image_up(t_game *g);
void		object_put(char *str, t_game *game, int y);
int			start_game(t_game *game);
int			map_update(t_game *game);
int			game_exit(t_game *game);
void		player_object_update(t_game *game);

#endif
