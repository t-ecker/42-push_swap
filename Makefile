NAME = push_swap
NAME_BONUS = checker

LIBFT_REPO = https://github.com/t-ecker/42-Libft.git
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Werror -Wextra


SRC =		./src/main.c \
			./src/algo.c \
			./src/utils1.c \
			./src/utils2.c \
			./src/utils3.c \
			./src/operations/push.c \
			./src/operations/swap.c \
			./src/operations/rotate.c

SRC_BONUS =	./src/checker.c \
			./src/utils1.c \
			./src/utils2.c \
			./src/utils3.c \
			./src/operations/push.c \
			./src/operations/swap.c \
			./src/operations/rotate.c

OBJ_DIR = ./obj
SRC_DIR = ./src

OBJ_FILES		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_FILES_BONUS	=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS))

all: $(NAME)
	clear;
	@$(MAKE) loading
	clear;

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):	$(LIBFT_DIR)/.git
	@make extra -C $(LIBFT_DIR)

$(LIBFT_DIR)/.git:
	@echo "\033[33mInitializing Libft submodule...\033[0m"
	@git submodule update --init --recursive
	@echo "\033[32mLibft submodule initialized.\033[0m"

VISUALIZER_REPO = https://github.com/o-reo/push_swap_visualizer.git
VISUALIZER_DIR = ./push_swap_visualizer

$(VISUALIZER_DIR):
	@echo "\n\033[33mAdding Push Swap Visualizer...\033[0m"
	git clone $(VISUALIZER_REPO) $(VISUALIZER_DIR)
	@echo "\033[32mPush Swap Visualizer cloned successfully.\033[0m"

visualizer: $(VISUALIZER_DIR)
	@mkdir -p $(VISUALIZER_DIR)/build
	@cd $(VISUALIZER_DIR)/build && cmake .. && make
	@echo "\033[32mPush Swap Visualizer built successfully.\033[0m"
	@echo "\n\033[1mTo run the visualizer:\033[0m\n\n\t1. \033[33mNavigate to the build directory:\033[0m\n\t\tcd $(VISUALIZER_DIR)/build\n\n\t2. \033[33mRun the visualizer:\033[0m\n\t\t./bin/visualizer\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(NAME_BONUS)
	clear;
	@$(MAKE) loading
	clear;

$(NAME_BONUS):	$(LIBFT) $(OBJ_FILES_BONUS) 
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

loading:
	@for i in {1..42}; do \
		printf '%s' "█"; \
		sleep 0.01; \
	done

.PHONY: all clean fclean re loading bonus visualizer
