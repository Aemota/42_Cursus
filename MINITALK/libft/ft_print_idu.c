/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_idu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:09:45 by albjimen          #+#    #+#             */
/*   Updated: 2022/11/03 20:33:36 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// especificadores %d y %i

int	ft_putnbr(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}

// especificador %u

int	ft_putunsignbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
	{
		ft_putchar(n + 48);
		len++;
	}
	else
	{
		len += ft_putunsignbr(n / 10);
		len += ft_putunsignbr(n % 10);
	}
	return (len);
}
