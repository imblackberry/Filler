/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:47:34 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 16:47:35 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/filler.h"

int		main(void)
{
	t_game *game;

	game = NULL;
	start_game(&game);
	free_game(&game);
	return (0);
}

void	start_game(t_game **game)
{
	set_game_struct(game);
	set_player_sign(game);
	set_opponent_sign(game);
	while (set_game(game) >= 0)
	{
		if ((put_piece_everywhere(game)) < 0)
			break ;
		search_one_xy_case(game);
		show_turn_result(*game);
		free_game_my_turn(game);
	}
	show_turn_result(*game);
	free_game_my_turn(game);
}

void	set_game_struct(t_game **game)
{
	(*game) = (t_game*)malloc(sizeof(t_game));
	if ((*game))
	{
		(*game)->my_sign = '\0';
		(*game)->opponent_sign = '\0';
		(*game)->file = NULL;
		(*game)->arrfile = NULL;
		(*game)->distance_map = NULL;
		(*game)->map = NULL;
		(*game)->piece = NULL;
		(*game)->valid_case = NULL;
		(*game)->x = 0;
		(*game)->y = 0;
	}
}

void	set_opponent_sign(t_game **game)
{
	if ((*game)->my_sign == 'X')
		(*game)->opponent_sign = 'O';
	else
		(*game)->opponent_sign = 'X';
}


int	set_player_sign(t_game **game)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
    if (line == NULL)
        return (-1);
	if (line[10] == '1')
		(*game)->my_sign = 'O';
	else if (line[10] == '2')
		(*game)->my_sign = 'X';
	ft_strdel(&line);
    return (0);
}
