/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_one_xy_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:29:23 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/04 15:29:25 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    show_double_int_arr(int **arr, int size_x, int size_y)
{
    int i;
	int j;

	j = 0;
    i = 0;
    while (i < size_y)
    {
		j = 0;
		printf("[%d]\t", i);
		while(j < size_x)
		{
			printf("|%d|", arr[i][j]);
			printf("\t");
			j++;
		}
        printf("\n");
        i++;
    }
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
	// printf("\t\t\t\t\t\t\tmin distance = %d\n", min_distance);
	return (min_distance);
}

void	set_valid_case_distance(t_game *game)
{
	t_case *valid_case;
	int i_map;
	int j_map;
	
	valid_case = game->valid_case;
	while (valid_case)
	{
		// printf("valid_case\n\t x = %d y = %d\n", valid_case->x, valid_case->y);
		i_map = valid_case->y;
		j_map = valid_case->x;
		valid_case->distance = min_distance_in_piece(j_map, i_map, game);
		valid_case = valid_case->next;
	}
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
	// printf("RESULT X = %d Y = %d\n", (*game)->x, (*game)->y);
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

void	set_distance_map(t_game **game)
{
	int **dist_map;

	dist_map = new_two_d_int_array((*game)->map->size_x, (*game)->map->size_y);
	(*game)->distance_map = dist_map;
	set_opponent_distance(game);
	set_each_distance(game);
}

int	point_exist_in_map(t_square *map, int i, int j)
{
	return (i >= 0 && j >= 0 && i < map->size_y && j < map->size_x);
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
		while(j < 2)
		{
			if (point_exist_in_map(map, y + i, y + j) && distance_map[0][y + i][x + j] == -1)
			{
				distance_map[0][y + i][x + j] = by_it;
			}
			j++;
		}
		i++;
	}
}
void	search_surrounding_point(t_game **game, int surround_it)
{
	t_square *map;
	int **distance_map;
	int i;
	int j;

	map = (*game)->map;
	distance_map = (*game)->distance_map;
	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while(j < map->size_x)
		{
			if (distance_map[i][j] == surround_it)
				surround_the_point(map, &distance_map, i, j);
			j++;
		}
		i++;
	}
}

int	can_put_distance(int **distance_map, int size_x, int size_y)
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

void	set_each_distance(t_game **game)
{
	int surround_it;
	int **distance_map;
	t_square *map;

	map = (*game)->map;
	distance_map = (*game)->distance_map;
	surround_it = 0;
	while (can_put_distance(distance_map, map->size_x, map->size_y))
	{
		search_surrounding_point(game, surround_it);
		surround_it++;
	}
	show_double_int_arr(distance_map, map->size_x, map->size_y);
}

int **new_two_d_int_array(int size_x, int size_y)//****************malloc
{
	int **new;
	int i;
	int j;

	i = 0;
	j = 0;
	new = (int**)malloc(sizeof(int*) * size_y);
	while(i < size_y)
	{
		j = 0;
		new[i] = (int*)malloc(sizeof(int) * size_x);
		while(j < size_x)
		{
			new[i][j] = NEW;
			j++;
		}
		i++;
	}
	return (new);
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
			if (compare_to_upper_and_low((*game)->map->arr[i][j], (*game)->opponent_sign))
				(*game)->distance_map[i][j] = 0;
			j++;
		}
		i++;
	}
}


int	search_minimum_distance(t_case	*valid_case)
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

