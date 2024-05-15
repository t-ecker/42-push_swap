# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tecker <tecker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 20:06:54 by tecker            #+#    #+#              #
#    Updated: 2024/05/15 12:17:28 by tecker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GREEN = \033[0;32m
# NC = \033[0m

PUSHSWAP = push_swap
CHECKER = checker
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra


OBJ =		push_swap.o \
			algo.o \
			utils1.o \
			utils2.o \
			utils3.o \
			./operations/push.o \
			./operations/swap.o \
			./operations/rotate.o \

OBJ_BONUS =	checker.o \
			utils1.o \
			utils2.o \
			utils3.o \
			./operations/push.o \
			./operations/swap.o \
			./operations/rotate.o \

all: $(PUSHSWAP)
# @clear
# @echo "$(GREEN)Build push_swap successfully.$(NC)"

$(PUSHSWAP): $(LIBFT) $(OBJ)
	@cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(PUSHSWAP)


bonus:	$(CHECKER)
# @clear
# @echo "$(GREEN)Build checker successfully.$(NC)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(CHECKER): $(LIBFT) $(OBJ_BONUS)
	@cc $(CFLAGS) $(LIBFT) $(OBJ_BONUS) -o $(CHECKER)

clean:
	@rm -f *.o 
	@rm -f ./operations/*.o
	@make clean -C $(LIBFT_DIR)
# @clear
# @echo "$(GREEN)Cleaned successfully$(NC)"
	
fclean: clean
	@rm -f $(PUSHSWAP) $(CHECKER)
	@make fclean -C $(LIBFT_DIR)
# @clear
# @echo "$(GREEN)Fully cleaned$(NC)"

re: fclean all

.PHONY: all clean bonus fclean re

