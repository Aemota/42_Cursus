# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 18:36:34 by albjimen          #+#    #+#              #
#    Updated: 2023/05/31 18:38:47 by albjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/parser.c srcs/parser_utils.c srcs/moves.c srcs/moves2.c srcs/sort.c srcs/radix.c
OBJS = obj/main.o obj/parser.o obj/parser_utils.o obj/moves.o obj/moves2.o obj/sort.o obj/radix.o

LIBFT = libft/libft.a 
INC = -I libft -I includes

VPATH = ./srcs

all: $(NAME)

$(NAME): $(LIBFT) obj $(OBJS)
	gcc $(CFLAGS) $(INC) -o $(NAME) $(LIBFT) $(OBJS)

obj:
	@mkdir obj

obj/%.o: %.c
	@gcc $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -rf obj/
	make -C libft/ clean
	
fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

rre: clean all

.PHONY: all clean fclean re 