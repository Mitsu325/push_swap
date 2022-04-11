# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 01:28:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/04/11 05:18:47 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	src
OBJ			=	obj
SUB_DIR		=	lst num put str

LST_F		=	ft_lstadd_back.c ft_lstclear.c
NUM_F		=	ft_atoi.c ft_isdigit.c ft_itoa.c
PUT_F		=	ft_putchar_fd.c ft_putlst_fd.c ft_putstr_fd.c
STR_F		=	ft_split.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_strlen.c \
				ft_substr.c

FILES		=	$(foreach file, $(LST_F), $(SRC)/lst/$(file))
FILES		+=	$(foreach file, $(NUM_F), $(SRC)/num/$(file))
FILES		+=	$(foreach file, $(PUT_F), $(SRC)/put/$(file))
FILES		+=	$(foreach file, $(STR_F), $(SRC)/str/$(file))

OBJ_DIR		=	$(foreach dir, $(SUB_DIR), $(addprefix $(OBJ)/, $(dir)))
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

# =============== TEST ===============

TEST		=	tests
TEST_DIR	=	lst num put str
TESTS		=	$(wildcard $(TEST)/*.c)
TESTS		+=	$(wildcard $(TEST)/lst/*.c)
TESTS		+=	$(wildcard $(TEST)/num/*.c)
TESTS		+=	$(wildcard $(TEST)/put/*.c)
TESTS		+=	$(wildcard $(TEST)/str/*.c)
TESTBIN_DIR	=	$(foreach dir, $(TEST_DIR), $(addprefix $(TEST)/bin/, $(dir)))
TESTBINS	=	$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

$(TEST)/bin/%:	$(TEST)/%.c
				@mkdir -p $(TEST)/bin/ $(TESTBIN_DIR)
				@$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lcriterion

test:			CFLAGS+=-fsanitize=address
test:			tclean $(NAME) $(TESTBINS)
				@for test in $(TESTBINS) ; do ./$$test ; done

test_v:			CFLAGS+=-fsanitize=address
test_v:			tclean $(NAME) $(TESTBINS)
				@for test in $(TESTBINS) ; do ./$$test --verbose ; done

tclean:		fclean
				@$(RM) $(TESTBINS)
				@$(RM) $(TEST)/bin

# ====================================

.PHONY:			all clean fclean re test test_v tclean
