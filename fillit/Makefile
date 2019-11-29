# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:43:46 by bhoth             #+#    #+#              #
#    Updated: 2019/10/15 21:04:35 by bhoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit 

# directories
SRC_DIR	:= ./
INC_DIR	:= ./
OBJ_DIR	:= ./obj
LIB_DIR	:= ./

# src / obj files
SRC		:= main.c \
		   get_next_line.c \
		   solution.c \
		   solution_functions.c \
		   elements.c \
		   check_solution.c \
		   check_element.c
OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c99
OFLAGS	:= -pipe -flto
CFLAGS	+= $(OFLAGS)

# libraries
L_FT	:= $(LIB_DIR)/libft

include $(L_FT)/lib.mk

.PHONY: all clean fclean re

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(L_FT) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(L_FT) re --no-print-directory
	@$(MAKE) re --no-print-directory