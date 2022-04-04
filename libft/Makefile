# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 01:28:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/04/04 05:06:56 by pmitsuko         ###   ########.fr        #
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

# =============== TEST ===============

TEST		=	tests
TEST_DIR	=	num
TESTS		=	$(wildcard $(TEST)/*.c)
TESTS		+=	$(wildcard $(TEST)/num/*.c)
TESTBIN_DIR	=	$(foreach dir, $(TEST_DIR), $(addprefix $(TEST)/bin/, $(dir)))
TESTBINS	=	$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

$(TEST)/bin/%:	$(TEST)/%.c
				@mkdir -p $(TEST)/bin/ $(TESTBIN_DIR)
				@$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lcriterion

test:			test_clean $(NAME) $(TESTBINS)
				for test in $(TESTBINS) ; do ./$$test ; done

test_v:			test_clean $(NAME) $(TESTBINS)
				for test in $(TESTBINS) ; do ./$$test --verbose ; done

test_clean:		fclean
				@$(RM) $(TESTBINS)
				@$(RM) $(TEST)/bin

# ====================================

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
