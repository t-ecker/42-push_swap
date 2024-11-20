NAME = push_swap
CHECKER = checker

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

OBJ_FILES		=	$(patsubst ./src/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_FILES_BONUS	=	$(patsubst ./src/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS))

all: $(NAME)
	clear;
	@$(MAKE) loading
	clear;

$(NAME): $(LIBFT) $(OBJ_FILES) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT)

$(LIBFT):	$(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

$(LIBFT_DIR):
	@echo "\n\033[33mAdding Libft submodule...\033[0m"
	touch .gitmodules
	git submodule add -f "$(LIBFT_REPO)" $(LIBFT_DIR)
	@echo "\033[32mLibft submodule added successfully.\033[0m"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: ./src/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(CHECKER)
	clear;
	@$(MAKE) loading
	clear;

$(CHECKER):	$(LIBFT) $(OBJ_FILES_BONUS) 
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_FILES_BONUS) $(LIBFT)

clean:
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(CHECKER)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

loading:
	@for i in {1..42}; do \
		printf '%s' "█"; \
		sleep 0.01; \
	done

.PHONY: all clean fclean re loading bonus
