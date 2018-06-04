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

int **new_two_d_int_array(int x, int y)
{
	int **new;
	int i;

	i = 0;
	new = (int**)malloc(sizeof(int*) * y);
	while(i <= y)
	{
		j = 0
		new[i] = (int*)malloc(sizeof(int) * x);
		while(j <= x)
		{
			new[i][j] = NEW;
			j++;
		}
		i++;
	}
	return (new);
}






void	set_mine_and_opponent_distance(t_game **game)
{
	int i;
	int j;

	i = 0;
	while (i <= (*game)->map->y)
	{
		j = 0;
		while (j <= (*game)->map->x)
		{
			if ((*game)->map->arr[i][j] == (*game)->my_sign)
				(*game)->distance_map[i][j] == 1;
			else if ((*game)->map->arr[i][j] == (*game)->my_sign)
				(*game)->distance_map[i][j] == 0;
			j++;
		}
		i++;
	}
}

void set_each_distance(t_game **game)
{
	int opp_x;
	int opp_y;
	int surround;

	surround = 2;
	set_mine_and_opponent_distance(game);
	opp_x = search_opponent_x(game);
	opp_y = search_opponent_y(game);
	while()//  not mine sign
	{
		surround_the_point((*game)->distance_map,  surround)
	}


}

int	*set_distance_map(t_game **game)
{
	(*game)->distance_map = new_two_d_int_array((*game)->map->x, (*game)->map->y);
	set_each_distance(game);
}

void	search_one_xy_case(t_game **game)
{
	t_case *min_distance;

	(*game)->distance_map = set_distance_map(game);
	fill_distance(game);
	min_distance = search_minimum_distance((*game)->valid_case);
	set_result(game, min_distance);
}

int		**fill_distance(t_game **game)
{
	t_case *map;
	int i;
	int j;

	i = 0;
	map = (*game)->map;
	while (i < map->y)
	{
		j = 0;
		while(j < map->x)
		{
			
		}
	}

}

int	search_minimum_distance(t_case	*valid_case)
{
	int distance;

	distance = 0;
	while (valid_case)
	{
		put_piece_on_distance();
		if (distance > valid_case->distance)
			distance = valid_case->distance;
		valid_case = valid_case->next;
	}
	return (distance);
}

