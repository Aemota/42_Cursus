/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charpp_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:34:28 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/21 17:22:06 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charpp_len(char **charpp)
{
	int	i;

	i = 0;
	if (!charpp || !charpp[i])
		return (0);
	while (charpp[i])
		i++;
	return (i);
}

char	**ft_charpp_cpy(char **charpp)
{
	char	**ret;
	int		i;

	if (!charpp)
		return (NULL);
	ret = ft_calloc(sizeof(char *), ft_charpp_len(charpp) + 1);
	i = 0;
	while (charpp[i])
	{
		ret[i] = ft_strdup(charpp[i]);
		i++;
	}
	return (ret);
}
