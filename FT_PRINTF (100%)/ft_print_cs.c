/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:36:55 by albjimen          #+#    #+#             */
/*   Updated: 2022/09/21 17:52:37 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// función para especificador %c

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

// función para especificador %s

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	i += ft_strlen(str);
	return (i);
}
