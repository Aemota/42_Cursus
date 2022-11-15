/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:33:10 by albjimen          #+#    #+#             */
/*   Updated: 2022/05/16 13:45:17 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(ft_strlen((char *)s1) + 1);
	if (!s2)
		return (0);
	ft_strlcpy(s2, (char *)s1, ft_strlen((char *)s1) + 1);
	return (s2);
}
