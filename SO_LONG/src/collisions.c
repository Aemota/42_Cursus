/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:13:36 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/21 18:32:41 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_coins(t_game *game, int next_x, int next_y)
{
	int	i;

	i = 0;
	if (game->map[next_y][next_x] == 'C')
	{
		while (i < game->total_coins)
		{
			if (game->coin_img->instances[i].x == next_x
				* 128 && game->coin_img->instances[i].y == next_y
				* 128 && game->coin_img->instances[i].enabled == true)
			{
				game->coin_img->instances[i].enabled = false;
				game->coins--;
				break ;
			}
			i++;
		}
		if (game->coins == 0 && game->open_exit == 0)
			game->open_exit = 1;
	}
}

int	handle_collisions(t_game *game, char dir)
{
	int	next_y;
	int	next_x;

	next_y = game->y_player;
	next_x = game->x_player;
	if (dir == 'w')
		next_y--;
	else if (dir == 'a')
		next_x--;
	else if (dir == 's')
		next_y++;
	else if (dir == 'd')
		next_x++;
	if (game->map[next_y][next_x] == '1')
		return (0);
	handle_coins(game, next_x, next_y);
	game->y_player = next_y;
	game->x_player = next_x;
	return (1);
}
