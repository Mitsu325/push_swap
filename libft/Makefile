# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 01:28:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/04/05 22:58:43 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	src
OBJ			=	obj
SUB_DIR		=	num str

NUM_F		=	ft_atoi.c ft_isdigit.c
STR_F		=	ft_split.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_strlen.c \
				ft_substr.c

FILES		=	$(foreach file, $(NUM_F), $(SRC)/num/$(file))
FILES		+= $(foreach file, $(STR_F), $(SRC)/str/$(file))

OBJ_DIR		= 	$(foreach dir, $(SUB_DIR), $(addprefix $(OBJ)/, $(dir)))
OBJS		=	$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(FILES))

INCLUDES	=	-I includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	/bin/rm -rf

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar -rcs $(NAME) $(OBJS)
				@ranlib $(NAME)

$(OBJ)/%.o	:	$(SRC)/%.c
				@mkdir -p $(OBJ) $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) -r $(OBJ)

re:				fclean all

.PHONY:			all clean fclean re
