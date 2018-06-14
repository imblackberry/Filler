/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:50:17 by vblokha           #+#    #+#             */
/*   Updated: 2017/12/07 16:55:49 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 1

typedef	struct		s_mylst
{
	int				fd;
	char			*content;
	struct s_mylst	*next;
}					t_mylst;
typedef	struct		s_struct
{
	char			*str;
	int				ret;
	int				k;
}					t_struct;
int					get_next_line(const int fd, char **line);

#endif
