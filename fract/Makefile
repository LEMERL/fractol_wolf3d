# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/13 14:48:43 by scoudert          #+#    #+#              #
#    Updated: 2015/07/30 12:18:58 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g

DEBUG = $(CFLAGS) -g

NAME = fractol

MLX_DIR = mlx/minilibx_macos/

MLX = $(MLX_DIR)/libmlx.a -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

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

RM = rm -rf

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ) Makefile
	@make -C libft/
	@make -C $(MLX_DIR)
	@echo "[frct]\033[32mCompile all \".c\"\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) libft/libft.a $(MLX)
	@echo "[frct]\033[36mCreate $(NAME) executable \033[0m"

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
