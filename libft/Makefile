#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblokha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 18:57:54 by vblokha           #+#    #+#              #
#    Updated: 2018/01/25 18:02:45 by vblokha          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

INC = includes/libft.h 

SRCDIR = sources/

SRC = ft_memalloc.c	ft_putendl.c	ft_strcpy.c	ft_strmapi.c	ft_strsub.c\
ft_memccpy.c	ft_putendl_fd.c	ft_strdel.c	ft_strncat.c	ft_strtrim.c\
ft_atoi.c	ft_memchr.c	ft_putnbr.c	ft_strdup.c	ft_strncmp.c	ft_tolower.c\
ft_bzero.c	ft_memcmp.c	ft_putnbr_fd.c	ft_strequ.c	ft_strncpy.c	ft_toupper.c\
ft_isalnum.c	ft_memcpy.c	ft_putstr.c	ft_striter.c	ft_strnequ.c\
ft_isalpha.c	ft_memdel.c	ft_putstr_fd.c	ft_striteri.c	ft_strnew.c	\
ft_isascii.c	ft_memmove.c	ft_strcat.c	ft_strjoin.c	ft_strnstr.c\
ft_isdigit.c	ft_memset.c	ft_strchr.c	ft_strlcat.c	ft_strrchr.c\
ft_isprint.c	ft_putchar.c	ft_strclr.c	ft_strlen.c	ft_strsplit.c\
ft_itoa.c	ft_putchar_fd.c	ft_strcmp.c	ft_strmap.c	ft_strstr.c \
ft_lstnew.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstdel.c\
ft_countwords.c ft_lstdisplay.c ft_del.c ft_lstaddend.c ft_count_if.c ft_itoa_base.c\
ft_strtoupper.c ft_putnbr_s.c ft_putnbr_u.c ft_putstrlen.c ft_s_num_width.c ft_u_num_width.c\
get_next_line.c ft_free_char_double_arr.c compare_to_upper_and_low.c ft_join_free.c \
ft_free_int_double_arr.c ft_new_double_int_arr.c

OBJDIR = objects/

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@echo "made all objects"
	@ar rc $(NAME) $(OBJ)
	@echo "made lib"
	@ranlib $(NAME)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	@gcc -Wall -Wextra -Werror -I $(INC) -c $< -o $@

clean:
	@echo cleaned objects
	@rm -rf $(OBJDIR)

fclean: clean
	@echo cleaned lib
	@rm -f $(NAME)

re: fclean all