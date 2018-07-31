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

SRCDIR = sources/

OBJDIR = objects/

OBJ =  $(addprefix $(OBJDIR), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJ)
	@gcc $(OBJ) libft/libft.a -o $(NAME)
	@echo MADE PLAYER

$(LIBFT):
	@make -C libft

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	@gcc $(FLAGS) -I headers/filler.h -c $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader

showing:
	gcc ./bonus/main.c ./bonus/read_filler.c ./bonus/show_score.c ./bonus/show_filler.c ./libft/libft.a -lncurses -o ./bonus/showing

clean:
	@make clean -C libft
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C libft
	@echo clean PLAYER
	@rm -f $(NAME)

re: fclean all