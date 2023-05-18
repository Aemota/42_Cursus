/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charpp_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:47:42 by albjimen          #+#    #+#             */
/*   Updated: 2023/03/19 20:28:09 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_charpp_add(char **charpp, char *str)
{
	char	**ret;
	int		i;

	if (!charpp)
		return (NULL);
	if (!str)
		return (charpp);
	ret = ft_calloc(sizeof(char *), ft_charpp_len(charpp) + 2);
	i = 0;
	while (charpp[i])
	{
		ret[i] = ft_strdup(charpp[i]);
		i++;
	}
	ret[i] = ft_strdup(str);
	ft_charpp_free(charpp);
	return (ret);
}
