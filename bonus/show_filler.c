/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:27:09 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/20 19:27:10 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

void	show_filler(char **game_arr)
{
	t_square	*show_map;
	int			i;

	i = 0;
	i = search_new_map_position(game_arr);
	set_show_map_size(&show_map, game_arr[i]);
	show_filler_in_windows(game_arr + i, show_map);
	free(show_map);
}

void	show_filler_in_windows(char **game_arr, t_square *show_map)
{
	int		i;
	WINDOW * map_w;
	WINDOW * score_w;
	i = 0;
	initscr();
	curs_set(0);
	start_color();
	set_windows(show_map, &map_w, &score_w);
	while (game_arr[i])
	{
		i += search_new_map_position(game_arr + i);
		if (show_score(&score_w, game_arr + i) == 1)
			break ;
		show_game_map(map_w, game_arr + i, show_map);
		sleep_and_refresh_w(&map_w, 30000);
		i++;
	}
	getch();
	endwin();
}

void	set_windows(t_square *show_map, WINDOW **map_w, WINDOW **score_w)
{
	int size_y;
	int size_x;

	size_y = 0;
	size_x = 0;
	size_y = show_map->size_y;
	size_x = show_map->size_x;
	*map_w = newwin(size_y + (START_MAP_Y * 2), size_x * 2 + 3
	+ (START_MAP_X * 2), 0, 0);
	*score_w = newwin(SCORE_Y_SIZE, SCORE_X_SIZE, 0, size_x * 2+ 3
	+ (START_MAP_X * 3));
	box(*map_w, 0, 0);
	wrefresh(*map_w);
	box(*score_w, 0, 0);
}

void	show_game_map(WINDOW *map_w, char **game_arr, t_square *show_map)
{
	int i;
	int j;

	i = START_MAP_Y;
	while (i < show_map->size_y + START_MAP_Y)
	{
		j = START_MAP_X;
		while (j < show_map->size_x + START_MAP_X)
		{
			show_character(map_w, i, j, game_arr[i][j]);
			j++;
		}
		i++;
	}
}

void	show_character(WINDOW *map_w, int i, int j, char c)
{
	short color_pair;

	color_pair = 0;
	init_pair(X_COLOR_PAIR, COLOR_BLACK, COLOR_YELLOW);
	init_pair(O_COLOR_PAIR, COLOR_BLACK, COLOR_RED);
	init_pair(DOT_COLOR_PAIR, COLOR_BLACK, COLOR_BLACK);
	if (c == 'O' || c == 'o')
		color_pair = O_COLOR_PAIR;
	else if (c == 'X' || c == 'x')
		color_pair = X_COLOR_PAIR;
	else if (c == '.')
		color_pair = DOT_COLOR_PAIR;
	wattron(map_w, COLOR_PAIR(color_pair));
	mvwprintw(map_w, i, j * 2 - 3, "   ", c);
	wattroff(map_w, COLOR_PAIR(color_pair));
}
