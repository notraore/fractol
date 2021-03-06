# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: notraore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 16:56:22 by lramirez          #+#    #+#              #
#    Updated: 2017/09/02 19:32:56 by notraore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
CC=gcc
SRC=srcs/main.c srcs/key_input.c srcs/errors.c srcs/man_init.c srcs/jul_init.c\
srcs/fractals.c srcs/nob_init.c srcs/multithread.c srcs/mouse_reset.c\
srcs/fractal_calc.c srcs/bonus_1.c srcs/bonus_2.c
OBJ=main.o key_input.o errors.o man_init.o jul_init.o fractals.o nob_init.o\
multithread.o mouse_reset.o fractal_calc.o bonus_1.o bonus_2.o
FLAGS=-Wall -Wextra -Werror
LIB=./libft/libft.a
MLX=-L ./miniLibx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@ echo "\033[92m\t\t\t---> ✓ libft created. ✓ <---\033[0m"
	@ make -C ./libft
	@ echo "\033[92m\t---> ✓ fractol program has been successfully created. ✓ <---\033[0m"
	@ $(CC) $(FLAGS) $(OBJ) -o $(NAME) $(MLX) $(LIB)
$(OBJ): $(SRC)
	@ $(CC) $(FLAGS) -c $(SRC)
clean:
	@ echo "\033[1;33m---> All .o files cleared. ✓ <---\033[0m"
	@ rm -f $(OBJ)
	@ make -C ./libft clean
fclean: clean
	@ echo "\033[1;33m---> Everything has been cleared. ✓ <---\033[2;00m"
	@ rm -f $(NAME)
	@ make -C ./libft fclean
re: fclean all

.PHONY: clean, fclean, re
