# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 14:48:43 by scoudert          #+#    #+#              #
#    Updated: 2015/06/08 01:22:33 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g

DEBUG = $(CFLAGS) -g

NAME = fractol

MLX_DIR = mlx/minilibx_macos/

MLX = -L$(MLX_DIR) -framework OpenGL -framework AppKit -lmlx

CC = gcc

SRC = main.c \
	  mlxr.c \
	  frct_calculus.c \
	  frct_init.c \
	  ft_fatal_error.c \
	  frct_mlx.c \
	  fractal.c

HEADER = ./libft/includes/

OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ)
	@make -C libft/
	@make -C $(MLX_DIR)
	@echo "[frct]\033[32mCompile all \".c\"\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(MLX_DIR)/libmlx.a $(OBJ) mlx/minilibx_macos/libmlx.a $(MLX) libft/libft.a
	@echo "[frct]\033[36mCreate $(NAME) executable \033[0m"

clean:
	@make -C libft/ clean
	@echo "[frct]\033[31mDelete all \".o\"\033[0m"
	$(RM) $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@make -C $(MLX_DIR) clean
	@echo "[frct]\033[31mDelete $(NAME) executable\033[0m"
	@$(RM) $(NAME)

re: fclean all
