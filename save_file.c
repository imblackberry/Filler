/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:57:27 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:57:29 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	assign_null(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

int		read_to_end(char **line, int *to_end, int *i)
{
	int ret;

	ret = 1;
	if (get_next_line(0, line) <= 0 || (!ft_strcmp("", (*line)) && !(*to_end)))
		ret = -1;
	
	if (ft_strstr(*line, "Piece"))
		*to_end = ft_atoi((*line) + PIECE);
	else if (*to_end)
		(*i)++;
	return (ret);
}

int		save_file(t_game **game)
{
	char	*line;
	char	*newline;
	int		i;
	int		to_end;
	int		ret;

	ret = 1;
	i = 0;
	to_end = 0;
	line = NULL;
	newline = ft_strdup("\n");
	while (i < to_end || !to_end)
	{
		if ((ret = read_to_end(&line, &to_end, &i)) <= 0)
			break ;
		if (!(*game)->file)
			(*game)->file = ft_strdup(line);
		else
			ft_join_free(&(*game)->file, line);
		ft_join_free(&(*game)->file, newline);
		ft_strdel(&line);
	}
	ft_strdel(&newline);
	ft_strdel(&line);
	return (ret);
}
