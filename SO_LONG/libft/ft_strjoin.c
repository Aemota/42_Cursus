/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:11:59 by albjimen          #+#    #+#             */
/*   Updated: 2022/05/16 12:24:54 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_s;

	if (!s1 || !s2)
		return (0);
	new_s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new_s)
		return (0);
	i = 0;
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_s[i++] = s2[j++];
	}
	new_s[i] = '\0';
	return (new_s);
}
