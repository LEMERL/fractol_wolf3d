# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 18:26:04 by mgrimald          #+#    #+#              #
#    Updated: 2015/02/28 17:11:22 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -L/usr/X11/lib -lmlx -lXext -lX11

CFLAGS = -Wall -Wextra -Werror $(MLX)

DEBUG = $(CFLAGS) -g

NAME = wolf2d

CC = gcc

SRC = main.c \
	  mlxr.c \
	  wlf_get_strc.c \
	  wlf_get_tab.c \
	  wolf2d_mlx.c \
	  move.c

HEADER = ./libft/includes/

OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@make -C libft/ fclean
	@make -C libft/
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
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
	@$(CC) $(DEBUG) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate $(NAME)\033[0m"

mlx_free:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo -e "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) -o $(NAME) $(OBJ) libft/libft.a
	@echo -e "\033[36mCreate \033[0m"
