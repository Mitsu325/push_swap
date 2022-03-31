# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 01:28:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/03/31 02:29:44 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	src
OBJ			=	obj
SUB_DIR		=	num

NUM_F		=	ft_atoi.c ft_isdigit.c

FILES		=	$(foreach file, $(NUM_F), $(SRC)/num/$(file))

OBJ_DIR		= 	$(foreach dir, $(SUB_DIR), $(addprefix $(OBJ)/, $(dir)))
OBJS		=	$(subst $(SRC), $(OBJ), $(FILES:.c=.o))

INCLUDES	=	-I includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	/bin/rm -f

$(OBJ)/%.o	:	$(SRC)/%.c
				@mkdir -p $(OBJ) $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar -rcs $(NAME) $(OBJS)
				@ranlib $(NAME)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) -r $(OBJ)

re:				fclean all

.PHONY:			all clean fclean re
