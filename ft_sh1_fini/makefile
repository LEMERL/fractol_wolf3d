# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 18:26:04 by mgrimald          #+#    #+#              #
#    Updated: 2015/05/17 14:21:10 by mgrimald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

DEBUG = $(CFLAGS) -g

NAME = ft_minishell1

CC = gcc

SRC = access.c \
	  builtin.c \
	  env_autre.c \
	  exec.c \
	  gestion_env.c \
	  get_command.c \
	  main.c \
	  sh_cd.c \
	  signal.c \
	  split_cmd.c

HEADER = ./libft/includes/

OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all, clean, fclean, re, debug, propre

all:
	@make $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(CFLAGS) $(SRC) -I $(HEADER) -o $(NAME) libft/libft.a
	@echo "\033[36mCreate $(NAME) executable \033[0m"

propre: $(NAME) clean

libft/libft.a:
	@make -C libft

%.o: %.c
	@echo "\033[32mCompile $< into $@\033[0m"
	@$(CC) $(CFLAGS) -c $< -I $(HEADER) -o $@

clean:
	@make -C libft/ clean
	@echo "\033[31m[$(NAME)]Delete all \".o\"\033[0m"
	@$(RM) $(OBJ)

fclean:
	@make -C libft/ fclean
	@echo "\033[31m[$(NAME)]Delete all \".o\"\033[0m"
	@$(RM) $(OBJ)
	@echo "\033[31mDelete $(NAME) executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo "\033[32m[$(NAME)]Compile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(DEBUG) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate $(NAME)\033[0m"
