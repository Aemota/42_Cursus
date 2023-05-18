/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:19:12 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/23 17:47:43 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initializer(t_game *game)
{
	game->coins = 0;
	game->player = 0;
	game->exit = 0;
	game->open_exit = 0;
	game->terminate = 0;
	game->moves = 0;
}

static void	check_elements(char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != 'P')
				ft_exit_error("Caracteres no válidos");
			else if (map[i][j] == 'E')
				game->exit++;
			else if (map[i][j] == 'P')
				game->player++;
			else if (map[i][j] == 'C')
				game->coins++;
		}
	}
}

void	check_elements_2(t_game *game)
{
	if (game->coins == 0)
		ft_exit_error("No hay monedas en el mapa");
	else if (game->player == 0 || game->player > 1)
		ft_exit_error("Número incorrecto de jugadores");
	else if (game->exit == 0 || game->exit > 1)
		ft_exit_error("Número incorrecto de salidas");
}

static void	check_walls(char **map)
{
	int	map_len;
	int	i;

	map_len = ft_charpp_len(map);
	if (map_len < 3)
		ft_exit_error("El mapa no tiene líneas suficientes");
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			ft_exit_error("El mapa no es rectangular");
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			ft_exit_error("El mapa no está rodeado de muros");
		i++;
	}
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[map_len - 1][i] != '1')
			ft_exit_error("El mapa no está rodeado de muros");
		i++;
	}
}

char	**parser(int argc, char **argv, t_game *game)
{
	char	**map;
	int		fd;

	initializer(game);
	if (argc != 2)
		ft_exit_error("Argumentos no válidos");
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber"))
		ft_exit_error("Nombre del archivo no válido");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit_error("Fallo con fd");
	map = read_map(fd);
	check_elements(map, game);
	check_elements_2(game);
	check_walls(map);
	check_path(map, game);
	game->total_coins = game->coins;
	close(fd);
	return (map);
}
