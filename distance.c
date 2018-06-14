/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:23:56 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:23:58 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_valid_case_distance(t_game *game)
{
	t_case	*valid_case;
	int		i_map;
	int		j_map;

	valid_case = game->valid_case;
	while (valid_case)
	{
		i_map = valid_case->y;
		j_map = valid_case->x;
		valid_case->distance = min_distance_in_piece(j_map, i_map, game);
		valid_case = valid_case->next;
	}
}

void	set_each_distance(t_game **game)
{
	int			surround_it;
	int			**distance_map;
	t_square	*map;

	map = (*game)->map;
	distance_map = (*game)->distance_map;
	surround_it = 0;
	while (can_put_distance(distance_map, map->size_x, map->size_y))
	{
		search_surrounding_point(game, surround_it);
		surround_it++;
	}
}

void	set_opponent_distance(t_game **game)
{
	int i;
	int j;

	i = 0;
	while (i < (*game)->map->size_y)
	{
		j = 0;
		while (j < (*game)->map->size_x)
		{
			if ((*game)->map->arr[i][j] == (*game)->opponent_sign)
				(*game)->distance_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		search_minimum_distance(t_case *valid_case)
{
	int distance;

	distance = 0;
	while (valid_case)
	{
		if (distance > valid_case->distance || !distance)
			distance = valid_case->distance;
		valid_case = valid_case->next;
	}
	return (distance);
}

int		can_put_distance(int **distance_map, int size_x, int size_y)
{
	int i;
	int j;

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			if (distance_map[i][j] == -1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
