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
INC = ./includes/
SRCS = ./ft_memalloc.c	ft_putendl.c	ft_strcpy.c	ft_strmapi.c	ft_strsub.c\
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
get_next_line.c ft_free_double_arr.c

OBJ = ./ft_atoi.o	ft_memccpy.o	ft_strchr.o	ft_strncmp.o\
ft_bzero.o	ft_memchr.o	ft_strcmp.o	ft_strncpy.o\
ft_isalnum.o	ft_memcmp.o	ft_strcpy.o	ft_strnstr.o\
ft_isalpha.o	ft_memcpy.o	ft_strdup.o	ft_strrchr.o\
ft_isascii.o	ft_memmove.o	ft_strlcat.o	ft_strstr.o\
ft_isdigit.o	ft_memset.o	ft_strlen.o	ft_tolower.o\
ft_isprint.o	ft_strcat.o	ft_strncat.o	ft_toupper.o\
ft_itoa.o	ft_putendl_fd.o	ft_strdel.o	ft_strmapi.o\
ft_memalloc.o	ft_putnbr.o	ft_strequ.o	ft_strnequ.o\
ft_memdel.o	ft_putnbr_fd.o	ft_striter.o	ft_strnew.o\
ft_putchar.o	ft_putstr.o	ft_striteri.o	ft_strsplit.o\
ft_putchar_fd.o	ft_putstr_fd.o	ft_strjoin.o	ft_strsub.o\
ft_putendl.o	ft_strclr.o	ft_strmap.o	ft_strtrim.o \
ft_lstnew.o ft_lstdelone.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_lstdel.o\
ft_countwords.o ft_lstdisplay.o ft_del.o ft_lstaddend.o ft_count_if.o ft_itoa_base.o\
ft_strtoupper.o ft_putnbr_s.o ft_putnbr_u.o ft_putstrlen.o ft_s_num_width.o ft_u_num_width.o\
get_next_line.o ft_free_double_arr.o

all: $(NAME)

$(NAME): $(SRCS) ./includes/libft.h
	gcc  -Wall -Wextra -Werror -c $(SRCS) -I $(INC)
	ar rc $(NAME) $(OBJ) 
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all