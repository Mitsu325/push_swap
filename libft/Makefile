# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 01:28:38 by pmitsuko          #+#    #+#              #
#    Updated: 2022/05/14 10:25:04 by pmitsuko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = -I includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC_DIR = ./src/

VPATH = $(SRC_DIR)\
		$(SRC_DIR)check\
		$(SRC_DIR)lst\
		$(SRC_DIR)num\
		$(SRC_DIR)put\
		$(SRC_DIR)str

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

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

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

.PHONY: all clean fclean re
