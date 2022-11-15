# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 17:38:12 by albjimen          #+#    #+#              #
#    Updated: 2022/11/08 20:33:23 by albjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

#INC es una variable que me permite incluir .h a la hora de compilar

INC = -I libft

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT) server.c
	gcc $(CFLAGS) $(INC) $(LIBFT) -o $(SERVER) server.c

$(CLIENT): $(LIBFT) client.c
	gcc $(CFLAGS) $(INC) $(LIBFT) -o $(CLIENT) client.c

# make -C hace make dentro de la carpeta que vaya seguida del "-C"

$(LIBFT):
	make -C libft

# make -C añadiendo clean hace make clean dentro de la carpeta que vaya seguida del "-C"

clean:
	make -C libft clean

fclean: clean
	rm -rf $(SERVER) $(CLIENT)
	make -C libft fclean

re: fclean all

.PHONY: all fclean clean re