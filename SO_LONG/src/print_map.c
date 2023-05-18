/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:04:36 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/21 18:57:42 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("pngs/floor.png");
	if (!texture)
		ft_exit_error("Fallo al cargar las texturas");
	game->floor_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("pngs/coin.png");
	game->coin_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("pngs/player.png");
	game->player_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("pngs/wall.png");
	game->wall_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("pngs/exit.png");
	game->exit_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("pngs/win.png");
	game->win_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	print_image(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_image_to_window(game->mlx, game->wall_img, x * 128, y * 128);
	else if (c == 'C')
		mlx_image_to_window(game->mlx, game->coin_img, x * 128, y * 128);
	else if (c == 'E')
		mlx_image_to_window(game->mlx, game->exit_img, x * 128, y * 128);
}

void	print_map(t_game *game)
{
	int	y;
	int	x;

	get_images(game);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->floor_img, x * 128, y * 128);
			if (game->map[y][x] != '0')
				print_image(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->player_img, game->x_player * 128,
		game->y_player * 128);
}
