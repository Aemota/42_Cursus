/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:01:42 by albjimen          #+#    #+#             */
/*   Updated: 2022/05/18 14:09:24 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static size_t	len_str(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static void	free_tab(char **tab, size_t n)
{
	if (!tab[n])
	{
		while (n > 0)
			free(tab[n--]);
		free(tab);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	str_n;
	size_t	n;
	size_t	len;

	if (!s)
		return (0);
	str_n = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (str_n + 1));
	if (!split)
		return (0);
	n = 0;
	while (n < str_n)
	{
		while (*s == c)
			s++;
		len = len_str(s, c);
		split[n] = (char *)malloc(sizeof(char) * (len + 1));
		free_tab(split, n);
		ft_strlcpy(split[n], (char *)s, len + 1);
		s = s + len;
		n++;
	}
	split[str_n] = 0;
	return (split);
}
