# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 23:50:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/05/14 10:31:07 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a
LIBFT_DIR = ./libft/
HEADER = -I includes -I $(LIBFT_DIR)includes
LIB_FLAGS = -L $(LIBFT_DIR) -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC_DIR = ./src/

VPATH = $(SRC_DIR)\
		$(SRC_DIR)parser\
		$(SRC_DIR)operation\
		$(SRC_DIR)sort\
		$(SRC_DIR)utils

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
		quicksort.c\
		stack_utils.c\
		parser_utils.c

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

$(OBJ_DIR)%.o: %.c
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		@echo "------------ MAKE PUSH SWAP ------------\n"
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
		@echo "------------- CLEANING DONE ------------\n"

re: fclean all

.PHONY: all clean fclean re
