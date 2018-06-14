/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_and_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:02:44 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:02:45 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_map(t_game **game)
{
	(*game)->map = (t_square*)malloc(sizeof(t_square));
	set_square_size(&(*game)->map, (*game)->arrfile[0], PLATEAU + 1);
	set_square_arr((*game)->arrfile + START_MAP_Y, &(*game)->map, START_MAP_X);
}

void	set_piece(t_game **game)
{
	int i;

	i = START_MAP_Y + (*game)->map->size_y;
	(*game)->piece = (t_square*)malloc(sizeof(t_square));
	set_square_size(&(*game)->piece, (*game)->arrfile[i], PIECE + 1);
	set_square_arr((*game)->arrfile + i + 1, &(*game)->piece, 0);
}

void	set_square_arr(char **arrfile, t_square **square, int start_x)
{
	int i;

	i = 0;
	(*square)->arr = (char**)malloc(sizeof(char*) * ((*square)->size_y + 1));
	while (i < (*square)->size_y)
	{
		(*square)->arr[i] = ft_strsub(*(arrfile + i), start_x,
		(*square)->size_x);
		i++;
	}
	(*square)->arr[i] = 0;
}

void	set_square_size(t_square **square, char *size_str, int start_digital)
{
	int i;
	int size_x;
	int size_y;

	i = start_digital;
	size_y = ft_atoi(size_str + i);
	while (size_str[i] != ' ')
		i++;
	size_x = ft_atoi(size_str + i);
	(*square)->size_x = size_x;
	(*square)->size_y = size_y;
}

void	set_distance_map(t_game **game)
{
	int **dist_map;

	dist_map = ft_new_double_int_arr((*game)->map->size_x,
	(*game)->map->size_y);
	(*game)->distance_map = dist_map;
	set_opponent_distance(game);
	set_each_distance(game);
}
