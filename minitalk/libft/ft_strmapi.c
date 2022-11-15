/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:19:03 by albjimen          #+#    #+#             */
/*   Updated: 2022/05/20 12:00:54 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	newstr = ft_strdup(s);
	if (!newstr)
		return (NULL);
	i = 0;
	while (newstr[i])
	{
		newstr[i] = (*f)(i, newstr[i]);
		i++;
	}
	return (newstr);
}
