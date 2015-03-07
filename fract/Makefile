# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 18:26:04 by mgrimald          #+#    #+#              #
#    Updated: 2015/03/07 18:28:12 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

DEBUG = $(CFLAGS) -g

NAME = fractol

CC = gcc

MLX = -framework OpenGL -framework AppKit -lmlx

SRC = main.c \
	  mlxr.c \
	  frct_calculus.c \
	  frct_init.c \
	  ft_fatal_error.c

HEADER = ./libft/includes/

OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(CFLAGS) -o $(OBJ) $(MLX) -o $(NAME) libft/libft.a
	@echo "\033[36mCreate $(NAME) executable \033[0m"


clean:
	@make -C libft/ clean
	@echo "\033[31mDelete all \".o\"\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@echo "\033[31mDelete $(NAME) executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate $(NAME)\033[0m"

mlx_free:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo -e "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) -o $(NAME) $(OBJ) libft/libft.a
	@echo -e "\033[36mCreate fdf\033[0m"
