/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:31:56 by albjimen          #+#    #+#             */
/*   Updated: 2022/05/20 14:31:05 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*temp;

	if (start + len > (size_t)ft_strlen(s))
		len = (size_t)ft_strlen(s) - start;
	if (len == 0 || (size_t)ft_strlen(s) < start)
		return (ft_strdup(""));
	str = malloc((len + 1) * sizeof(char));
	if (!str || !s)
		return (NULL);
	*str = '\0';
	s += start;
	temp = str;
	while (len-- && *s)
	{
		*temp = *s;
		temp++;
		s++;
	}
	*temp = '\0';
	return (str);
}
