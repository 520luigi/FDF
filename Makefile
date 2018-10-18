# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szheng <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 20:12:07 by szheng            #+#    #+#              #
#    Updated: 2018/10/02 22:30:58 by szheng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fdf

SRCS = srcs/main.c srcs/read.c srcs/draw.c

INC = -I includes/fdf.h -I libft/

LIB = -L minilibx_macos/ -l mlx -L libft/ -lft

FRM = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@mkdir -p obj/
	@make -C minilibx_macos
	@make -C libft
	@gcc -Wall -Werror -Wextra -c $(SRCS) $(INC)
	@mv *.o obj/
	@gcc obj/*.o $(LIB) -o $(NAME) $(FRM)
	@echo "FDF is ready to go!"

clean:
	@make -C minilibx_macos/ clean
	@make -C libft/ clean
	@rm -rf obj/
	@echo "Removed Object files"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Removed FDF executable"

re: fclean all
