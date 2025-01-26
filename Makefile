NAME = minesweeper
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = 	src/minesweeper.c \
		src/arg.c \
		src/exit.c \
		src/load_sprite.c \
		src/map.c \
		src/load_map.c \
		src/key_hook.c \
		src/mouse_hook.c \

OBJ = $(SRC:.c=.o)

LIBFTDIR = Libft/
LIBFT = $(LIBFTDIR)libft.a

MLXDIR = minilibx-linux/
MLX = $(MLXDIR)libmlx.a

HEADER = src/minesweeper.h

GREEN = \033[32m
RESET = \033[0m

all: header $(LIBFT) $(MLX) $(NAME)

header:
	@echo "$(GREEN)"
	@echo "-----------------------------------------------------------------"
	@echo "|     _     ___       __                _       _            __ |"
	@echo "|    (_)___/ (_)___  / /_   ____  _____(_)___ _(_)___  ___  / / |"
	@echo "|   / / __  / / __ \/ __/  / __ \/ ___/ / __ \`/ / __ \/ _ \/ /  |"
	@echo "|  / / /_/ / / /_/ / /_   / /_/ / /  / / /_/ / / / / /  __/ /   |"
	@echo "| /_/\__,_/_/\____/\__/   \____/_/  /_/\__, /_/_/ /_/\___/_/    |"
	@echo "|                                     /____/                    |"
	@echo "-----------------------------------------------------------------"
	@echo "$(RESET)"

$(NAME): $(OBJ) $(HEADER) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLXDIR) -lmlx -L$(LIBFTDIR) -lft -lXext -lX11 -lm -lbsd -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLXDIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re header
