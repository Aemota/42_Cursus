/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:12:09 by albjimen          #+#    #+#             */
/*   Updated: 2022/11/03 20:33:36 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_eval_format(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (format == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len = ft_printptr(va_arg(args, void *));
	else if (format == 'd')
		len = ft_putnbr(va_arg(args, unsigned int));
	else if (format == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len = ft_putunsignbr(va_arg(args, unsigned int));
	else if (format == 'x')
		len = ft_printhex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len = ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	i = 0;
	len = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_eval_format(format[++i], args);
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/* int	main(void)
{
	printf("%d", ft_printf("hola\n CHAR: %c\n STR: %s\nmundo\n", 'g',
				"CARAJO"));
	printf("%d", ft_printf("MIN HEX %x\nMAYU HEX %X\n", 36453, 36453));
	printf("%d", ft_printf("MIN HEX %x\nMAYU HEX %X\n", 252, 252));
	printf("%d", ft_printf("MIN HEX %x\nMAYU HEX %X\n", 36453576, 36453576));
	printf("%d", ft_printf("d: %d\ni: %i\n", 2147483647, -2147483648));
	printf("%d", ft_printf("d: %d\ni: %i\n", -2147483648, 2147483647));
	return (0);
}
 */