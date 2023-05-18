/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:13:03 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/23 18:27:58 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_fill(int y, int x, char **map_copy)
{
	if (map_copy[y][x + 1] != '1' && map_copy[y][x + 1] != 'F')
	{
		map_copy[y][x] = 'F';
		map_fill(y, x + 1, map_copy);
	}
	if (map_copy[y][x - 1] != '1' && map_copy[y][x - 1] != 'F')
	{
		map_copy[y][x] = 'F';
		map_fill(y, x - 1, map_copy);
	}
	if (map_copy[y + 1][x] != '1' && map_copy[y + 1][x] != 'F')
	{
		map_copy[y][x] = 'F';
		map_fill(y + 1, x, map_copy);
	}
	if (map_copy[y - 1][x] != '1' && map_copy[y - 1][x] != 'F')
	{
		map_copy[y][x] = 'F';
		map_fill(y - 1, x, map_copy);
	}
	map_copy[y][x] = 'F';
}

int	ft_is_invalid(char **map_copy, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'C' || map[y][x] == 'E') && map_copy[y][x] != 'F')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	check_path(char **map, t_game *game)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = ft_charpp_cpy(map);
	y = -1;
	while (map_copy[++y])
	{
		x = -1;
		while (map_copy[y][++x])
		{
			if (map_copy[y][x] == 'P')
			{
				map_fill(y, x, map_copy);
				game->x_player = x;
				game->y_player = y;
			}
		}
	}
	if (ft_is_invalid(map_copy, map))
		ft_exit_error("No hay camino válido");
	ft_charpp_free(map_copy);
}
