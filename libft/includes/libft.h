/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:18:07 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/14 16:20:58 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(char *src);
size_t				ft_strlcat(char *dst, const char *src,
	size_t dstsize);
char				*ft_strncat(char *s1, const char *s2,
	size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src,
	size_t n);
void				*ft_memccpy(void *dst, const void *src,
	int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
unsigned long long	ft_putchar(char c);
unsigned long long	ft_putstr(char const *s);
unsigned long long	ft_putendl(char const *s);
unsigned long long	ft_putnbr(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int,
	char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char
	(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2,
	size_t n);
char				*ft_strsub(char const *s,
	unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const
	*s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
unsigned long long	ft_putchar_fd(char c, int fd);
unsigned long long	ft_putstr_fd(char const *s, int fd);
unsigned long long	ft_putendl_fd(char const *s, int fd);
unsigned long long	ft_putnbr_fd(int n, int fd);
typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void const *content, size_t
	content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newlst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *,
	size_t));
size_t				ft_countwords(char const *s, char c);
void				ft_lstdisplay(t_list *lst);
void				ft_del(void *content, size_t size);
t_list				*ft_lstaddend(t_list *list1, t_list *lst2);
int					ft_count_if(char **tab, int (*f)(char*));
char				*ft_itoa_base(unsigned long long int n, int base);
char				*ft_strtoupper(char *s);
unsigned long long	ft_putnbr_s(signed long long int n);
unsigned long long	ft_putnbr_u(unsigned long long int n);
unsigned long long	ft_putstrlen(char *str, int len);
int					ft_s_num_width(long long int n, int div);
int					ft_u_num_width(unsigned long long int n, int div);
void				ft_free_char_double_arr(char ***arr);
int					compare_to_upper_and_low(char c, char lower_virsion);
void				ft_join_free(char **s1, char *s2);
void				ft_free_int_double_arr(int ***arr, int size_y);
int					**ft_new_double_int_arr(int size_x, int size_y);

#endif
