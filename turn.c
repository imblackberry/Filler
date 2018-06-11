/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:52:48 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 16:52:50 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	set_game(t_game **game)
{
	int ret;

	ret = 0;
    if (save_file(game) < 0)
		return (-1);
    (*game)->arrfile = ft_strsplit((*game)->file, '\n');
    set_map(game);
    set_piece(game);
	return (ret);
}

int	put_piece_everywhere(t_game **game)
{
    int map_i;
    int map_j;

    map_i = map_j = 0;
    while (map_i <= (*game)->map->size_y - (*game)->piece->size_y)
    {
        map_j = 0;
        while (map_j <= (*game)->map->size_x - (*game)->piece->size_x)
        {
			if (search_valid_cases(game, map_i, map_j))
                set_valid_case(game, map_i, map_j);
        	map_j++;
		}
    	map_i++;
    }
	if (!(*game)->valid_case)
		return (-1);
	return (0);
}

void	search_one_xy_case(t_game **game)
{
	int min_distance;

	set_distance_map(game);
	set_valid_case_distance(*game);
	min_distance = search_minimum_distance((*game)->valid_case);
	// printf("chosen = %d\n", min_distance);
	set_result(game, min_distance);
}

void	set_result(t_game **game, int min_distance)
{
	t_case *valid_case;	

	valid_case = (*game)->valid_case;
	while (valid_case)
	{
		if (valid_case->distance == min_distance)
		{
			(*game)->x = valid_case->x;
			(*game)->y = valid_case->y;
			break ;
		}
		valid_case = valid_case->next;
	}
}

void    show_turn_result(t_game *game)
{
    ft_putnbr(game->y);
	ft_putchar(' ');
	ft_putnbr(game->x);
	ft_putchar('\n');
}

