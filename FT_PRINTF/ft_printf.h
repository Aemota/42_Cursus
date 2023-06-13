/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:55:45 by albjimen          #+#    #+#             */
/*   Updated: 2022/09/21 19:55:22 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_eval_format(const char format, va_list args);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_printhex(unsigned long long num, char *str);
int		ft_putnbr(int n);
char	*ft_itoa(int n);
int		ft_putunsignbr(unsigned int n);
int		ft_printptr(void *ptr);
#endif