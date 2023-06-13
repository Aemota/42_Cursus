/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:19:30 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/25 19:27:38 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(const char *str);
long long		ft_atoll(const char *str);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isdigit_str(char *str);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *s1);
char			*ft_strnstr(const char *hays, const char *need, size_t len);
char			*ft_strrchr(const char *s, int c);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_printf(char const *format, ...);
int				ft_eval_format(const char format, va_list args);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_strlen(const char *str);
void			ft_putstr_fd(char *s, int fd);
int				ft_printhex(unsigned long long num, char *str);
int				ft_putnbr(int n);
char			*ft_itoa(int n);
int				ft_putunsignbr(unsigned int n);
int				ft_printptr(void *ptr);
char			*ft_get_line(char *str);
char			*ft_new_line(char *line);
char			*ft_read_line(int fd, char *backup);
char			*get_next_line(int fd);
int				gnl_strlen(char *s);
char			*gnl_strjoin(char *s1, char *s2);
char			*gnl_strchr(char *s, int c);
int				ft_charpp_len(char **charpp);
char			**ft_charpp_cpy(char **charpp);
char			**ft_charpp_add(char **charpp, char *str);
void			*ft_charpp_free(char **to_free);

#endif