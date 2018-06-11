#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblokha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 11:21:20 by vblokha           #+#    #+#              #
#    Updated: 2018/06/04 15:31:42 by vblokha          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = vblokha.filler

SRC = start_game.c turn.c case.c distance.c free_game.c point.c save_file.c set_map_and_piece.c

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