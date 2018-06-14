/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:44:07 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:44:10 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		point_exist_in_map(t_square *map, int i, int j)
{
	return (i >= 0 && i < map->size_y && j >= 0 && j < map->size_x);
}

void	surround_the_point(t_square *map, int ***distance_map, int y, int x)
{
	int surround_it;
	int by_it;
	int i;
	int j;

	i = -1;
	surround_it = distance_map[0][y][x];
	by_it = surround_it + 1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (point_exist_in_map(map, y + i, x + j) &&
			distance_map[0][y + i][x + j] == -1)
				distance_map[0][y + i][x + j] = by_it;
			j++;
		}
		i++;
	}
}

void	search_surrounding_point(t_game **game, int surround_it)
{
	t_square	*map;
	int			**distance_map;
	int			i;
	int			j;

	map = (*game)->map;
	distance_map = (*game)->distance_map;
	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if (distance_map[i][j] == surround_it)
				surround_the_point(map, &distance_map, i, j);
			j++;
		}
		i++;
	}
}
