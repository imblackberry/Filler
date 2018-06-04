#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblokha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 11:21:20 by vblokha           #+#    #+#              #
#    Updated: 2018/04/20 11:21:23 by vblokha          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = vblokha.filler

SRC = main.c

OBJ = ./$(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc  -o $(NAME) $(FLAGS) libft/libft.a $(SRC)

comp:
	gcc -g $(SRC) libft/libft.a

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all