# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 23:50:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/05/14 10:10:46 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = push_swap

# LIBRARY #

LIBFT = libft.a
LIBFT_DIR = ./libft/
HEADER = -I includes -I $(LIBFT_DIR)includes
LIB_FLAGS = -L $(LIBFT_DIR) -lft

# COMPILATION #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# DELETE #

RM = rm -rf

# DIRECTORIES #

SRC_DIR = ./src/

VPATH = $(SRC_DIR)\
		$(SRC_DIR)parser\
		$(SRC_DIR)operation\
		$(SRC_DIR)sort\
		$(SRC_DIR)utils

# FILES #

SRCS = main.c\
		parser_save.c\
		check_number.c\
		save_number.c\
		check_sort.c\
		swap.c\
		push.c\
		rotate.c\
		reverse_rotate.c\
		sort.c\
		simple_sort.c\
		simple_sort_helper.c\
		complex_sort.c\
		partition_a_and_push_b.c\
		push_biggest_numbers_to_a.c\
		push_small_number_pivot_to_b.c\
		sort_number_remain_a.c\
		quicksort.c\
		stack_utils.c\
		parser_utils.c

# COMPILED_SOURCES #

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

# **************************************************************************** #

## RULES ##

$(OBJ_DIR)%.o: %.c
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		@echo "\n$(CYAN)----------------------------------------"
		@echo "------------ MAKE PUSH SWAP ------------"
		@echo "----------------------------------------\n$(DEFAULT)"
		@$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAGS) $(HEADER) -o $(NAME)

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

$(LIBFT):
		@make --no-print-directory -C $(LIBFT_DIR)

clean:
		@make clean --no-print-directory -C $(LIBFT_DIR)
		@$(RM) $(OBJ_DIR)

fclean: clean
		@make fclean --no-print-directory -C $(LIBFT_DIR)
		@$(RM) $(NAME)
		@$(RM) valgrind-out.txt
		@echo "\n$(MAGENTA)----------------------------------------"
		@echo "------------- CLEANING DONE ------------"
		@echo "----------------------------------------\n$(DEFAULT)"

re: fclean all

# CHECK MEMORY LEAK #

release: CFLAGS+=-g -fsanitize=address
release: fclean
release: $(NAME)

# val: fclean
# val: $(NAME)
# val:
#		@valgrind --leak-check=full --log-file=valgrind-out.txt
#		./$(NAME) $(seq 1 100 | shuf | tr '\n' ' ')

# full-val: fclean
# full-val: $(NAME)
# full-val:
# @valgrind
# --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt
# ./$(NAME) $(seq 1 100 | shuf | tr '\n' ' ')

# NORMINETTE #

normi:
		@echo "\n$(YELLOW)----------------------------------------"
		@echo "-------------- NORMINETTE -------------"
		@echo "----------------------------------------\n$(DEFAULT)"
		@norminette includes libft/includes libft/src src/parser src/operation

debug: CFLAGS+=-g
debug: fclean
debug: $(NAME)

.PHONY: all clean fclean re release val full-val normi
