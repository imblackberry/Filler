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

void    show_int_arr(int **arr, int size_x, int size_y)
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
			j++;
		}
        printf("\n");
        i++;
    }
}

void	search_one_xy_case(t_game **game)
{
	t_case *min_distance;

	set_distance_map(game);
	// min_distance = search_minimum_distance((*game)->valid_case);
	// set_result(game, min_distance);
}

void	set_distance_map(t_game **game)
{
	int **dist_map;

	dist_map = new_two_d_int_array((*game)->map->size_x, (*game)->map->size_y);
	(*game)->distance_map = dist_map;
	set_opponent_distance(game);
	set_each_distance(game);
}

void	set_each_distance(t_game **game)
{
	t_square *map;
	int **distance_map;
	int i;
	int j;
	int surround_it;
	// int size_x;
	// int size_y;

	map = (*game)->map;
	distance_map = (*game)->distance_map;
	i = 0;
	surround_it = 0;
	while (i < map->size_y)
	{
		j = 0;
		while(j < map->size_x)
		{
			if (distance_map[i][j] == surround_it)
				surround_the_point(distance_map[i][j], distance_map[i][j] + 1);
			j++;
		}
		i++;
	}		
}

// int search_opponent(t_game **game, char type)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < (*game)->map->size_y)
// 	{
// 		j = 0;
// 		while (j < (*game)->map->size_x)
// 		{
// 			if ((*game)->map->arr[i][j] == (*game)->opponent_sign)
// 				return (type == 'y' ? i : j);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (-1);
// }

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






// void	fill_distance(int **distance_map, int size_x, int size_y)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < size_y)
// 	{
// 		j = 0;
// 		while(j < size_x)
// 		{
// 			if (distance_map[i][j] == 0)
// 				surround_the_point(distance_map[i][j], )
// 			j++;
// 		}
// 		i++;
// 	}
// }
// }

// int	search_minimum_distance(t_case	*valid_case)
// {
// 	int distance;

// 	distance = 0;
// 	while (valid_case)
// 	{
// 		put_piece_on_distance();
// 		if (distance > valid_case->distance)
// 			distance = valid_case->distance;
// 		valid_case = valid_case->next;
// 	}
// 	return (distance);
// }

