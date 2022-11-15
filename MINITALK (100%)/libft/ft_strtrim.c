/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:26:03 by albjimen          #+#    #+#             */
/*   Updated: 2022/05/17 13:00:15 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	findset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		i;
	int		start;
	int		end;

	if (s1 == 0 || set == 0)
		return (0);
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && findset(s1[start], set))
		start++;
	while (end > start && findset(s1[end - 1], set))
		end--;
	newstr = malloc(sizeof(char) * (end - start + 1));
	if (!newstr)
		return (0);
	i = 0;
	while (start < end)
	{
		newstr[i++] = s1[start++];
	}
	newstr[i] = '\0';
	return (newstr);
}
