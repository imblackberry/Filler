/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:40:39 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:40:41 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_case    *set_case_struct(int y, int x)
{
	t_case *valid_case;

	valid_case = (t_case*)malloc(sizeof(t_case));
	if (valid_case)
	{
		valid_case->x = x;
		valid_case->y = y;
		valid_case->distance = 0;
		valid_case->next = NULL;
	}
	return (valid_case);
}

void set_valid_case(t_game **game, int map_i, int map_j)
{
    t_case *new_case;
    t_case *tmp;

    new_case = set_case_struct(map_i, map_j);
    if (!(*game)->valid_case)
        (*game)->valid_case = new_case;
    else
    {
        tmp = (*game)->valid_case;
        while (tmp->next)
            tmp = tmp->next;
         tmp->next = new_case;
    }
}

int search_valid_cases(t_game **game, int map_i, int map_j)
{
    int i;
	int j;
	int opp_imposition;
    int my_imposition;

    i = j = opp_imposition = my_imposition = 0;
    while (i < (*game)->piece->size_y)
	{
        map_j -= j;
		j = 0;
		while(j < (*game)->piece->size_x)
		{
			if (check_sign(*game, (*game)->map->arr[map_i][map_j], (*game)->piece->arr[i][j]) == 1)
				my_imposition++;
            else if (check_sign(*game, (*game)->map->arr[map_i][map_j], (*game)->piece->arr[i][j]) == -1)
                opp_imposition++;
			j++;
            map_j++;
		}
		i++;
        map_i++;
	}
    if (my_imposition == 1 && opp_imposition == 0)
        return (1);
    return (0);
}

int check_sign(t_game *game, char map_sign, char piece_sign)
{
    if (piece_sign == '*' && map_sign == game->my_sign)
        return (1);
    else if (piece_sign == '*' && map_sign == game->opponent_sign)
        return (-1);
    return (0);
}

int	min_distance_in_piece(int j_map, int i_map, t_game *game)
{
	t_square *piece;
	int min_distance;
	int i;
	int j;

	i = j = 0;
	min_distance = 0;
	piece = game->piece;
	while (i < piece->size_y)
	{
		j = 0;
		while (j < piece->size_x)
		{
			if (piece->arr[i][j] == '*'  && 
			(game->distance_map[i_map + i][j_map + j] < min_distance || !min_distance))
				min_distance = game->distance_map[i_map + i][j_map + j];
			j++;
		}
		i++;
	}
	return (min_distance);
}