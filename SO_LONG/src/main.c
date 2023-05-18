/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:19:09 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/23 18:48:47 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_exit(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'E' &&
		game->open_exit == 1)
	{
		mlx_image_to_window(game->mlx, game->win_img,
			((ft_strlen(game->map[0]) - 2) / 2) * 128,
			((ft_charpp_len(game->map) - 2) / 2) * 128);
		game->terminate = 1;
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *data)
{
	t_game	*game;

	game = data;
	if (game->terminate == 1)
	{
		if ((keydata.key == MLX_KEY_ENTER && keydata.action == MLX_RELEASE)
			|| (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE))
			ft_exit_success(game);
	}
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_exit_success(game);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& handle_collisions(game, 'w'))
		make_move(game, 'w');
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& handle_collisions(game, 'a'))
		make_move(game, 'a');
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& handle_collisions(game, 's'))
		make_move(game, 's');
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& handle_collisions(game, 'd'))
		make_move(game, 'd');
	handle_exit(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = parser(argc, argv, &game);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game.mlx = mlx_init(ft_strlen(game.map[0]) * 128, ft_charpp_len(game.map)
			* 128, "so_long", true);
	if (!game.mlx)
		return (1);
	print_map(&game);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_loop(game.mlx);
}
