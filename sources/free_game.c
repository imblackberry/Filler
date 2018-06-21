/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:10:47 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:10:48 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/filler.h"

void	free_square(t_square **square)
{
	if (!square || !*square)
		return ;
	ft_free_char_double_arr(&(*square)->arr);
	(*square)->arr = NULL;
	(*square)->size_x = 0;
	(*square)->size_y = 0;
	free(*square);
	(*square) = NULL;
}

void	free_case(t_case **valid_case)
{
	t_case *tmp;

	if (*valid_case == NULL)
		return ;
	while ((*valid_case) != NULL)
	{
		tmp = (*valid_case)->next;
		free(*valid_case);
		*valid_case = NULL;
		*valid_case = tmp;
	}
}

void	free_game(t_game **game)
{
	free(*game);
	*game = NULL;
}

void	free_game_my_turn(t_game **game)
{
	t_square *map;

	map = (*game)->map;
	ft_strdel(&(*game)->file);
	ft_free_char_double_arr(&(*game)->arrfile);
	if ((*game)->map && (*game)->map->size_x && (*game)->map->size_y)
		ft_free_int_double_arr(&(*game)->distance_map, map->size_y);
	free_square(&(*game)->map);
	free_square(&(*game)->piece);
	free_case(&(*game)->valid_case);
	(*game)->x = 0;
	(*game)->y = 0;
}
