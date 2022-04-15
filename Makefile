# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 23:50:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/04/15 19:24:50 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

NAME		=	push_swap
SRC			=	src
OBJ			=	obj
SUB_DIR		=	tests parser

SRC_FILE	=	main.c
PARSER_FILE	=	parser_save.c check_number.c save_number.c check_sort.c

FILES		=	$(foreach file, $(SRC_FILE), $(SRC)/$(file))
FILES		+=	$(foreach file, $(PARSER_FILE), $(SRC)/parser/$(file))
FILES		+=	$(wildcard $(SRC)/tests/*.c)
FILES		+=	$(wildcard $(SRC)/tests/parser_save/*.c)
FILES		+=	$(wildcard $(SRC)/tests/integration/*.c)

OBJ_DIR		=	$(foreach dir, $(SUB_DIR), $(addprefix $(OBJ)/, $(dir)))
OBJS		=	$(subst $(SRC), $(OBJ), $(FILES:.c=.o))
TEST_OBJ_DIR	=	obj/tests/parser_save obj/tests/integration

HEADER		=	-I includes -I $(LIBFT_DIR)/includes
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIB_FLAGS	=	-L $(LIBFT_DIR) -lft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

all:		$(NAME)

$(NAME):		make_obj $(LIBFT) $(OBJS)
				@echo "\n$(CYAN)----------------------------------------"
				@echo "------------ MAKE PUSH SWAP ------------"
				@echo "----------------------------------------\n$(DEFAULT)"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

$(OBJ)/%.o:		$(SRC)/%.c
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

make_obj:
				@mkdir -p $(OBJ) $(OBJ_DIR) $(TEST_OBJ_DIR)

$(LIBFT):
				@make --no-print-directory -C $(LIBFT_DIR)

release:	CFLAGS+=-g -fsanitize=address
release:	fclean
release:	$(NAME)

val:		fclean
val:		$(NAME)
val:
			@valgrind --leak-check=full --log-file=valgrind-out.txt ./$(NAME) $(num)

full-val:	fclean
full-val:	$(NAME)
full-val:
			@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) $(num)

normi:
			@norminette libft/src src

.PHONY:		all clean fclean re release val full-val normi
