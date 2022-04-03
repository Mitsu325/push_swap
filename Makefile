# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 23:50:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/04/03 15:43:28 by pmitsuko         ###   ########.fr        #
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

HEADER		=	-I includes
LIBFT_DIR	=	libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIB_FLAGS	=	-L $(LIBFT_DIR) -lft -L /usr/local/lib

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf

all:			$(NAME)

release:		CFLAGS+=-fsanitize=address
release:		fclean
release:		$(NAME)

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
				@echo "\n$(MAGENTA)----------------------------------------"
				@echo "------------- CLEANING DONE ------------"
				@echo "----------------------------------------\n$(DEFAULT)"

re:				fclean all

.PHONY:			all clean fclean re
