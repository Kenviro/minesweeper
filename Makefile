# Nom des programmes
NAME = minesweeper
BONUS = bot_minesweeper

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Répertoires des sources
SRC_DIR = src
GAME_SRC_DIR = game_src
BOT_SRC_DIR = bot_src
OBJS_DIR = obj

# Sources
SRC = minesweeper.c \
      arg.c \
      exit.c \
      load_sprite.c \
      map.c \
      load_map.c \
      key_hook.c \
      mouse_hook.c

SRC_BOT = bot_action.c

# Objets
OBJS_SRC = $(addprefix $(OBJS_DIR)/, $(SRC:.c=.o))
OBJS_BOT = $(addprefix $(OBJS_DIR)/, $(SRC_BOT:.c=.o))

# Bibliothèques
LIBFTDIR = Libft
LIBFT = $(LIBFTDIR)/libft.a
MLXDIR = minilibx-linux
MLX = $(MLXDIR)/libmlx.a

# Headers
HEADER = $(SRC_DIR)/minesweeper.h
BOT_HEADER = $(BOT_SRC_DIR)/bot.h

# Liens externes
LIBS = -L$(MLXDIR) -lmlx -L$(LIBFTDIR) -lft -lXext -lX11 -lm -lbsd

# Couleurs
GREEN = \033[32m
RED = \033[31m
CYAN = \033[36m
RESET = \033[0m

# Règles principales
all: $(OBJS_DIR) header $(NAME)

bonus: $(OBJS_DIR) header $(BONUS)

$(NAME): $(OBJS_SRC) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS_SRC) $(LIBS) -o $@
	@echo "$(GREEN)Compilation réussie : $(NAME)$(RESET)"

$(BONUS): $(OBJS_BOT) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS_BOT) $(LIBS) -o $@
	@echo "$(GREEN)Compilation réussie : $(BONUS)$(RESET)"

# Création des fichiers objets pour src et game_src
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(GAME_SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Création des fichiers objets pour bot_src
$(OBJS_DIR)/%.o: $(BOT_SRC_DIR)/%.c $(BOT_HEADER)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Crée le répertoire obj s'il n'existe pas
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(CYAN)Répertoire obj/ créé$(RESET)"

# Compilation des bibliothèques
$(LIBFT):
	@make -C $(LIBFTDIR)
	@echo "$(CYAN)Libft compilée$(RESET)"

$(MLX):
	@make -C $(MLXDIR)
	@echo "$(CYAN)MiniLibX compilée$(RESET)"

# Nettoyage
clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBFTDIR) clean
	@make -C $(MLXDIR) clean
	@echo "$(RED)Fichiers objets supprimés$(RESET)"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)Binaires supprimés$(RESET)"

re: fclean all

# Affichage du header
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

.PHONY: all bonus clean fclean re header
