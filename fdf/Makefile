# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:43:46 by bhoth             #+#    #+#              #
#    Updated: 2020/02/02 15:32:21 by bhoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# src / obj files
SRC		:= 	main.c \
		   	get_next_line.c \
		   	read_map.c \
			convert_map.c \
			free.c

OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

NAME = fdf

INCLUDES = fdf.h

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJS)
		gcc -g -o $(NAME) $(OBJS) -L libft -lft

$(OBJS): %.o : %.c $(INCLUDES)
		gcc -Wall -Wextra -Werror -g -I./ -c $<

lib:
	@make -C libft

clean:
	/bin/rm -f $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

relibs:
	$(MAKE) -C $(LIBFT) re
	$(MAKE) re
