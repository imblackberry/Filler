/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 14:24:49 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/19 14:24:54 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "libft/libft.h"
# include "filler.h"
# define O_SCORE_LINE 4
# define X_SCORE_LINE 6
# define SCORE_X_SIZE 28
# define SCORE_Y_SIZE 9
# define X_COLOR_PAIR 1
# define O_COLOR_PAIR 2
# define DOT_COLOR_PAIR 3

char	**read_filler();
char	set_show_sign();
void    show_game_map(WINDOW *map_w, char **game_arr, t_square *show_map);
void	set_show_map_size(t_square **map, char *size_str);
char    *save_show_file();
void    save_game_file(char **file, char *line);

void	sleep_and_refresh_w(WINDOW **window, useconds_t seconds)
{
	usleep(seconds);
	wrefresh(*window);
}

int search_new_map_position(char **game_arr)
{
	int i;

	i = 0;
	while (game_arr[i] != NULL && !ft_strstr(game_arr[i], "Plateau")
	&& !ft_strstr(game_arr[i], "== O fin"))
            i++;
	return (i);
}
void set_windows(t_square *show_map, WINDOW **map_w, WINDOW **score_w)
{
	int size_y;
	int size_x;

	size_y = show_map->size_y;
	size_x = show_map->size_x;
    *map_w = newwin(size_y + (START_MAP_Y * 2), size_x * 2 + 3 + (START_MAP_X * 2), 0, 0);
	*score_w = newwin(SCORE_Y_SIZE, SCORE_X_SIZE, 0, size_x * 2 + 3 + (START_MAP_X * 3));
	box(*map_w, 0, 0);
    wrefresh(*map_w);
	box(*score_w, 0, 0);
}

void	set_results(char **game_arr, int *o_result, int *x_result)
{
	*o_result = ft_atoi(game_arr[0] + 9);
	*x_result = ft_atoi(game_arr[1] + 9);
}
void show_who_is_who(WINDOW **score_w, int o_result, int x_result)
{
	int loser_line;
	int winner_line;

	loser_line = 0;
	winner_line = 0;
	if (x_result == o_result)
	{
		mvwprintw(*score_w, O_SCORE_LINE, 2, "FUCKING"  );
		mvwprintw(*score_w, O_SCORE_LINE + 1, 3, "DRAW");
		mvwprintw(*score_w, O_SCORE_LINE + 2, 2, "HAHAHA");
		return ;
	}
	else if (x_result < o_result)
		winner_line = O_SCORE_LINE;
	else if (x_result > o_result)
		winner_line = X_SCORE_LINE;
	loser_line = (winner_line == X_SCORE_LINE) ? O_SCORE_LINE : X_SCORE_LINE;
	mvwprintw(*score_w, winner_line, 2, "FUCKING WINNER");
	mvwprintw(*score_w, loser_line, 2, "FUCKING LOSER");
}
int show_score(WINDOW **score_w, char **game_arr)
{
	int o_result;
	int x_result;

	if (ft_strstr(game_arr[0], "== O fin") != 0)
	{
		init_pair(X_COLOR_PAIR, COLOR_BLACK, COLOR_YELLOW);
		init_pair(O_COLOR_PAIR, COLOR_BLACK, COLOR_RED);
		set_results(game_arr, &o_result, &x_result);
	    mvwprintw(*score_w, 2, SCORE_X_SIZE / 2 - 2, "SCORE");
		wattron(*score_w, COLOR_PAIR(O_COLOR_PAIR));
		mvwprintw(*score_w, O_SCORE_LINE, 18, "O : %d", o_result);
		wattroff(*score_w, COLOR_PAIR(O_COLOR_PAIR));
		wattron(*score_w, COLOR_PAIR(X_COLOR_PAIR));
		mvwprintw(*score_w, X_SCORE_LINE, 18, "X : %d", x_result);
		wattroff(*score_w, COLOR_PAIR(X_COLOR_PAIR));
		show_who_is_who(score_w, o_result, x_result);// mvwprintw(*score);
		wrefresh(*score_w);
		usleep(300000000);
		return (1);
	}
	return (0);
}

int main()
{
	WINDOW *map_w;
	WINDOW *score_w;
    char **game_arr;
    int i;
	t_square *show_map;

    i = 0;
    game_arr = read_filler();
	i = search_new_map_position(game_arr);
    set_show_map_size(&show_map, game_arr[i]);
    initscr();
	curs_set(0);
	start_color();
    set_windows(show_map, &map_w, &score_w);
	while(game_arr[i])
	{	
		i += search_new_map_position(game_arr + i);
		if (show_score(&score_w, game_arr + i) == 1)
			break ;
		show_game_map(map_w, game_arr + i, show_map);
		sleep_and_refresh_w(&map_w, 30000);
        i++;
	}

    ft_free_char_double_arr(&game_arr);
	free(show_map);
    getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    endwin();
	// system("leaks a.out");
    return (0);
}

void	show_character(WINDOW *map_w, int i, int j, char c)
{
	short color_pair;
	color_pair = 0;
	init_pair(X_COLOR_PAIR, COLOR_BLACK, COLOR_YELLOW);
	init_pair(O_COLOR_PAIR, COLOR_BLACK, COLOR_RED);
	init_pair(DOT_COLOR_PAIR, COLOR_BLACK, COLOR_GREEN);
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

void    show_game_map(WINDOW *map_w, char **game_arr, t_square *show_map)
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

void	set_show_map_size(t_square **show_map, char *size_str)
{
	int i;

	i = 0;
    (*show_map) = (t_square*)malloc(sizeof(t_square));
	while(!ft_isdigit(size_str[i]))
		i++;
	(*show_map)->size_y = ft_atoi(size_str + i);
	while(ft_isdigit(size_str[i]))
		i++;
	(*show_map)->size_x = ft_atoi(size_str + i);
    (*show_map)->arr = NULL;
}



char	**read_filler()
{
    char **game_arr;
    char *game_str;

    game_str = save_show_file();
    game_arr = ft_strsplit(game_str, '\n');
    ft_strdel(&game_str);
    return (game_arr);
}

char    *save_show_file()
{
    char *line;
    char *file;

    file = NULL;
    line = NULL;
    while (get_next_line(0, &line) > 0)
    {           
        save_game_file(&file, line);
        if (ft_strstr(line, "== X fin:"))
            break ;
        ft_strdel(&line);
    }
    ft_strdel(&line);
    return (file);
}

void    save_game_file(char **file, char *line)
{
    char *newline;   
    
    newline = ft_strdup("\n");
    if (*file == NULL)
		*file = ft_strdup(line);
	else
		ft_join_free(file, line);
	ft_join_free(file, newline);
    ft_strdel(&newline);
}
