/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:20:04 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/21 18:58:10 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd)
{
	char	**map;
	char	*buff;
	char	*new_line;

	map = ft_calloc(sizeof(char *), 2);
	if (!map)
		return (NULL);
	buff = get_next_line(fd);
	if (!buff)
		return (ft_charpp_free(map),
			ft_exit_error("Fallo al leer el mapa"), NULL);
	new_line = ft_strtrim(buff, "\n");
	map[0] = new_line;
	free(buff);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break ;
		new_line = ft_strtrim(buff, "\n");
		map = ft_charpp_add(map, new_line);
		free(new_line);
		free(buff);
	}
	return (map);
}
