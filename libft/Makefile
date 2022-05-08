# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 01:28:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/05/06 06:46:00 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = -I includes

# COMPILATION #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# DELETE #

RM = rm -rf

# DIRECTORIES #

SRC_DIR = ./src/

VPATH = $(SRC_DIR)\
		$(SRC_DIR)check\
		$(SRC_DIR)lst\
		$(SRC_DIR)num\
		$(SRC_DIR)put\
		$(SRC_DIR)str

# FILES #

SRCS = ft_isdigit.c\
		ft_issignal.c\
		ft_isspace.c\
		ft_lstadd_back.c\
		ft_lstclear.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_putchar_fd.c\
		ft_putlst_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strlen.c \
		ft_substr.c

# COMPILED_SOURCES #

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

# **************************************************************************** #

## RULES ##

$(OBJ_DIR)%.o: %.c
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		@ar -rcs $(NAME) $(OBJS)
		@ranlib $(NAME)

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

clean:
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) -r $(OBJ_DIR)

re: fclean all

# **************************************************************************** #

## TESTS ##

TEST = tests
TEST_DIR = lst num put str
TESTS = $(wildcard $(TEST)/*.c)
TESTS += $(wildcard $(TEST)/lst/*.c)
TESTS += $(wildcard $(TEST)/num/*.c)
TESTS += $(wildcard $(TEST)/put/*.c)
TESTS += $(wildcard $(TEST)/str/*.c)
TESTBIN_DIR = $(foreach dir, $(TEST_DIR), $(addprefix $(TEST)/bin/, $(dir)))
TESTBINS = $(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

$(TEST)/bin/%: $(TEST)/%.c
		@mkdir -p $(TEST)/bin/ $(TESTBIN_DIR)
		@$(CC) $(CFLAGS) $< $(OBJS) -o $@ -lcriterion

test: CFLAGS+=-fsanitize=address
test: tclean $(NAME) $(TESTBINS)
		@for test in $(TESTBINS) ; do ./$$test ; done

test_v: CFLAGS+=-fsanitize=address
test_v: tclean $(NAME) $(TESTBINS)
		@for test in $(TESTBINS) ; do ./$$test --verbose ; done

tclean: fclean
		@$(RM) $(TESTBINS)
		@$(RM) $(TEST)/bin

.PHONY: all clean fclean re test test_v tclean
