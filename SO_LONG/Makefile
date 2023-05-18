# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 13:52:46 by albjimen          #+#    #+#              #
#    Updated: 2023/03/19 20:36:38 by albjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    = so_long

CFLAGS  = -Wall -Wextra -Werror

SRC		= src/main.c src/parser.c src/read_map.c src/utils.c src/check_path.c src/print_map.c src/make_move.c src/collisions.c

OBJ		= ${SRC:.c=.o}

LIBFT = libft/libft.a
INC = -I libft -I include -I MLX42/include/MLX42
MLX = MLX42/libmlx42.a

BREW = "/Users/$(USER)/.brew/opt/glfw/lib/"

%.o: %.c
	gcc $(CFLAGS) $(INC) -o $@ -c $<

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(MLX) -lglfw -L $(BREW) $(INC) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

$(MLX):
	make -C MLX42/

clean:
	rm -rf $(OBJ)
	make -C MLX42/ clean
	make -C libft/ clean
	
fclean: clean
	rm -f $(NAME)
	make -C MLX42/ fclean
	make -C libft/ fclean

re: fclean all

rre: clean all

.PHONY: all clean fclean re mlx42