# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 14:48:43 by scoudert          #+#    #+#              #
#    Updated: 2015/07/31 19:09:03 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -O3

DEBUG = $(CFLAGS) -g

NAME = fractol

MLX_DIR = mlx/minilibx_macos/

MLX = $(MLX_DIR)/libmlx.a -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRC = main.c \
	  mlxr.c \
	  frct_init.c \
	  ft_fatal_error.c \
	  frct_mlx.c \
	  fractal.c

HEADER = ./libft/includes/

OBJ = $(SRC:.c=.o)

RM = rm -rf

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): mandel

mandel: $(SRC)
	@make -C libft/
	@make -C $(MLX_DIR)
	@echo "[frct]\033[32mCompile all \".c\"\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) mandelbrot.c libft/libft.a $(MLX)
	@echo "[frct]\033[36mCreate $(NAME) executable for mandelbrot, julia, bird of prey and another\033[0m"

more: $(SRC)
	@make -C libft/
	@make -C $(MLX_DIR)
	@echo "[frct]\033[32mCompile all \".c\"\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) more.c libft/libft.a $(MLX)
	@echo "[frct]\033[36mCreate $(NAME) executable for perpandicular, it's julia's kind, ternaire and a last one\033[0m"

clean:
	@make -C libft/ clean
	@echo "[frct]\033[31mDelete all \".o\"\033[0m"
	$(RM) $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@make -C $(MLX_DIR) clean
	@echo "[frct]\033[31mDelete $(NAME) executable\033[0m"
	@$(RM) $(NAME) $(NAME).dSYM

re: fclean all
