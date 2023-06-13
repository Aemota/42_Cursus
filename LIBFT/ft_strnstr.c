/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:20:52 by albjimen          #+#    #+#             */
/*   Updated: 2022/05/16 13:46:03 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (need[i] == '\0')
		return ((char *)hays);
	while (hays[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && hays[i + j] == need[j])
		{
			if (need[j + 1] == '\0')
			{
				return ((char *)&hays[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}
