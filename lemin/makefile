NAME = lem-in

HDIR = ./includes/
SDIR = ./sources/
ODIR = ./objects/

SRC = parsing.c\
	  resolve.c\
	  find_all_path.c\
	 omg_path.c

OBJ = $(SRC:.c=.o)

SRC_C := $(addprefix $(SDIR), $(SRC))
SRC_O := $(addprefix $(ODIR), $(OBJ))

LIB_FT = -L libft/ -lft

CC = clang
#FLAGS = -Wall -Wextra -Werror -O3
FLAGS = -g

RED = \033[31m
CYAN = \033[36m
NORMAL = \033[00m
GREY = \033[90m

.PHONY: clean fclean all re propre

all: $(NAME)

$(NAME): $(SRC_O)
	@$(CC) -o $(NAME) $(SRC_O) $(LIB_MLX) $(LIB_FT) $(FRAM)
	@echo "$(CYAN)[$(NAME)]$(GREY) Executable created.$(NORMAL)"

$(SRC_O): $(SRC_C)
	@make -C libft/
	@echo "$(CYAN)[$(NAME)]$(GREY) Libft compiled.$(NORMAL)"
	@$(CC) $(FLAGS) -c $(SRC_C) -I $(HDIR)
	@if [ -d $(ODIR) ]; then\
		echo "$(CYAN)[$(NAME)]$(GREY) Objects Directory already exists.$(NORMAL)";\
	else\
		mkdir $(ODIR);\
	fi
	@mv $(OBJ) $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(GREY) Objects created.$(NORMAL)"

re: fclean all

clean:
	@rm -f $(SRC_O)
	@rm -rf $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"
	@make clean -C libft/
	@echo "$(CYAN)[$(NAME)]$(RED) Libft cleaned.$(NORMAL)"

fclean:
	@rm -f $(SRC_O)
	@rm -rf $(ODIR)
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)"
	@rm -f $(NAME)
	@echo "$(CYAN)[$(NAME)]$(RED) Executable deleted.$(NORMAL)"
	@make fclean -C libft/
	@echo "$(CYAN)[$(NAME)]$(RED) Libft cleaned.$(NORMAL)"

propre: all clean
