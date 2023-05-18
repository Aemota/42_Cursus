/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:43:07 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/23 17:50:51 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"

typedef struct s_game
{
	mlx_t		*mlx;
	char		**map;
	int			coins;
	int			player;
	int			exit;
	int			x_player;
	int			y_player;
	int			open_exit;
	int			terminate;
	int			total_coins;
	int			moves;
	mlx_image_t	*floor_img;
	mlx_image_t	*player_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*coin_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*win_img;
}				t_game;

char			**read_map(int fd);
char			**parser(int argc, char **argv, t_game *game);
void			ft_exit_error(char *error);
void			check_path(char **map, t_game *game);
void			print_map(t_game *game);
void			make_move(t_game *game, char dir);
int				handle_collisions(t_game *game, char dir);
void			ft_exit_success(t_game *game);

#endif