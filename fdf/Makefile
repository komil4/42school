# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhoth <bhoth@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:43:46 by bhoth             #+#    #+#              #
#    Updated: 2020/02/11 22:16:55 by bhoth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# src / obj files
SRC		:= 	main.c \
		   	get_next_line.c \
		   	read_map.c \
			convert_map.c \
			free.c \
			draw.c \
			math.c \
			deal.c \
			create.c \
			text.c \
			isometric_func.c

OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

NAME = fdf

INCLUDES = libft/libft.a minilibx_macos/libmlx.a

FLAGS = -Wall -Wextra -Werror

OPENGL = -L /usr/local/lib/ -lmlx -framework OpenGL \
	-framework AppKit

OBJS = $(SRC:.c=.o)

all: 
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc -g $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(OPENGL)

lib:
	@make -C libft

clean:
	/bin/rm -f $(OBJS)
	make -C libft clean
	make -C minilibx_macos clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean
	make -C minilibx_macos clean

re: fclean all

relibs:
	$(MAKE) -C $(LIBFT) re
	$(MAKE) re
