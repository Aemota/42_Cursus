/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:35:39 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/31 18:39:41 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char **arg, int argc)
{
	if (argc < 3)
		ft_charpp_free(arg);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_duplicate(char **arg, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_strcmp(arg[i], arg[index]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (!str || ((str[0] == '+' || str[0] == '-')
			&& !ft_isdigit(str[1])))
		return (0);
	else if ((str[0] == '+' || str[0] == '-'))
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_strlen(str) > 11)
		return (0);
	return (1);
}
