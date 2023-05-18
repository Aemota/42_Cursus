/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:17:17 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/21 18:49:10 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_move(t_game *game, char dir)
{
	if (dir == 'a')
		game->player_img->instances[0].x -= 128;
	else if (dir == 'w')
		game->player_img->instances[0].y -= 128;
	else if (dir == 's')
		game->player_img->instances[0].y += 128;
	else if (dir == 'd')
		game->player_img->instances[0].x += 128;
	game->moves++;
	ft_printf("MOVES: %d\n", game->moves);
}
