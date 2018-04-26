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

FT_PRINTF = ft_printf

SRC = main.c

OBJ = ./$(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(OBJ)

	gcc -c $(FLAGS) $(SRC) -o $(NAME)

comp:
	gcc -g $(SRC) ./ft_printf/libftprintf.a ./ft_printf/libft/libft.a

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all