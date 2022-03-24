# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 23:50:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/03/25 00:01:21 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRC			=	src
OBJ			=	obj

SRC_FILE	=	main.c

FILES		=	$(foreach file, $(SRC_FILE), $(SRC)/$(file))

OBJS		=	$(subst $(SRC), $(OBJ), $(FILES:.c=.o))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf

$(OBJ)/%.o:		$(SRC)/%.c
				@mkdir -p $(OBJ)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all:			$(NAME)
				@echo "\n\e[96m----------------------------------------"
				@echo "------------ MAKE PUSH SWAP ------------"
				@echo "----------------------------------------\n\e[0m"

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS)
				@$(RM) $(OBJ)

fclean:			clean
				@$(RM) $(NAME)
				@echo "\n\e[95m----------------------------------------"
				@echo "------------- CLEANING DONE ------------"
				@echo "----------------------------------------\n\e[0m"

re:				fclean all

.PHONY:			all clean fclean re
