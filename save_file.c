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

int    save_file(t_game **game)
{
    char *line;
    int ret;
    char *newline;
	int i;
	int to_end;
	
	to_end = 0;
	i = 0;
	ret = 1;
	line = NULL;
    newline = ft_strdup("\n");
    while (i < to_end || !to_end)
    {   
		if (get_next_line(0, &line) <= 0 || (!ft_strcmp("", line) && !to_end))
        {
			ret = -1;
            break ;
        }
		if (ft_strstr(line, "Piece"))
			to_end = ft_atoi(line + PIECE);
		else if (to_end)
			i++;
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
