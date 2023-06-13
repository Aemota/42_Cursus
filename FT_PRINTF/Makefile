# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 13:43:22 by albjimen          #+#    #+#              #
#    Updated: 2022/09/21 18:01:55 by albjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print_cs.c ft_print_hexpt.c ft_print_idu.c utils.c

OBJS = ${SRCS:.c=.o}

AR = ar rcs

RM = rm -f

%.o: %.c 
	gcc $(CFLAGS) -c $< ${<:.o=.c}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
