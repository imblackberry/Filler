#include <ncurses.h>
 #include "libft/libft.h"
# include "filler.h"

void	read_filler(WINDOW *map_w);
char	set_show_sign();

int main()
{
	WINDOW *map_w;

    initscr();
	map_w = newwin(20, 20, 0, 0);
	
	refresh();
	read_filler(map_w);
	wborder(map_w, '|', '|', '_', '_', '*', '*', '*', '*');
    wrefresh(map_w);

	while(1)
	{
		
		wrefresh(map_w);
	}

    getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    endwin();                    // Выход из curses-режима. Обязательная команда.
    return (0);
}

void	set_show_size(t_square **map)
{
	char *line;
	int i;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	while(!ft_isdigit(line[i]))
		i++;
	(*map)->size_y = ft_atoi(line + i);
	while(ft_isdigit(line[i]))
		i++;
	(*map)->size_x = ft_atoi(line + i);
}

void	set_show_arr(t_square **square)
{
	int i;
	char *line;
	int start_x;


	i = 0;
	line = NULL;
	start_x = 0;
	(*square)->arr = (char**)malloc(sizeof(char*) * ((*square)->size_y + 1));
	get_next_line(0, &line);
	if (ft_strchr(line, '0') == 0)
		start_x = START_MAP_X;
	ft_strdel(&line);
	while(i < (*square)->size_y)
	{
		get_next_line(0, &line);
		(*square)->arr[i] = ft_strsub(line, start_x, (*square)->size_x);
		ft_strdel(&line);
		i++;
	}
	(*square)->arr[i] = 0;
}

t_square	*set_show_square(t_square *square)
{
	set_show_size(&square);
	set_show_arr(&square);
	return (square);
}

void	read_filler(WINDOW *map_w)
{
	t_square *map;
	t_square *piece;
	char my_sign;

	my_sign = set_show_sign();
	map = set_show_square(map);
	piece = set_show_square(piece);
	mvwprintw(map_w, 2, 2, "map_size_x = %d map_size_y = %d\n p_size_x = %d p_size_y = %d\n", map->size_x, map->size_y, piece->size_x, piece->size_y);

}

char	set_show_sign()
{
	char *line;
	char my_sign;

	line = NULL;
	get_next_line(0, &line);
	if (line[10] == '1')
		my_sign = 'O';
	else if (line[10] == '2')
		my_sign = 'X';
	ft_strdel(&line);
	return (my_sign);
}
