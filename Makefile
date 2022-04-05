# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 23:50:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/04/05 23:11:03 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEFAULT		=	\e[39m
GREEN		=	\e[92m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

NAME		=	push_swap
SRC			=	src
OBJ			=	obj

SRC_FILE	=	main.c

FILES		=	$(foreach file, $(SRC_FILE), $(SRC)/$(file))

OBJS		=	$(subst $(SRC), $(OBJ), $(FILES:.c=.o))

HEADER		=	-I includes -I $(LIBFT_DIR)/includes
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIB_FLAGS	=	-L $(LIBFT_DIR)

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT)
				@echo "\n$(CYAN)----------------------------------------"
				@echo "------------ MAKE PUSH SWAP ------------"
				@echo "----------------------------------------\n$(DEFAULT)"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

$(OBJ)/%.o:		$(SRC)/%.c
				@mkdir -p $(OBJ)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(LIBFT):
				@make --no-print-directory -C $(LIBFT_DIR)

clean:
				@make clean --no-print-directory -C $(LIBFT_DIR)
				@$(RM) $(OBJS)
				@$(RM) $(OBJ)

fclean:			clean
				@make fclean --no-print-directory -C $(LIBFT_DIR)
				@$(RM) $(NAME)
				@$(RM) valgrind-out.txt
				@echo "\n$(MAGENTA)----------------------------------------"
				@echo "------------- CLEANING DONE ------------"
				@echo "----------------------------------------\n$(DEFAULT)"

re:				fclean all

# ============ CHECK NORMI AND MEMORY LEAK ============

release:		CFLAGS+=-g -fsanitize=address
release:		fclean
release:		$(NAME)

val:			fclean
val:			$(NAME)
val:
				@valgrind --leak-check=full --log-file=valgrind-out.txt ./$(NAME) $(num)

full-val:			fclean
full-val:			$(NAME)
full-val:
				@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) $(num)

normi:
				@norminette libft/src src

.PHONY:			all clean fclean re release val full-val normi
