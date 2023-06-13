/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexpt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:05:01 by albjimen          #+#    #+#             */
/*   Updated: 2022/09/21 19:53:03 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// función para especificador %p

int	ft_printptr(void *ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_printhex((unsigned long long)ptr, "0123456789abcdef");
	return (len);
}

// función para especificadores %x y %X

int	ft_printhex(unsigned long long num, char *str)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_printhex(num / 16, str);
	len += ft_putchar(str[num % 16]);
	return (len);
}
