#include <ncurses.h>
#include "libft/libft.h"
# include "filler.h"
char	**read_filler();
char	set_show_sign();
void    show_map(WINDOW *map_w, char **game_arr);

int main()
{
	WINDOW *map_w;
    char **game_arr;
    int i;

    i = 0;
    game_arr = read_filler();
    
    // system("leaks a.out");
    initscr();
	map_w = newwin(100, 100, 0, 0);
	
	wborder(map_w, '|', '|', '_', '_', '*', '*', '*', '*');
    wrefresh(map_w);
	while(game_arr[i])
	{
        
        
        while(game_arr[i] && !ft_strstr(game_arr[i], "Plateau"))
            i++;

        // mvwprintw(map_w, 1, 1, "_________________\n");
		show_map(map_w, game_arr + i);
        // show_map_with_piece(game_arr + i);

        wrefresh(map_w);
        i++;
	}
    
    // getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    endwin();                    // Выход из curses-режима. Обязательная команда.
    return (0);
}
char    *save_show_file();
void    save_game_file(char **file, char *line);
void	set_show_map_size(t_square **map, char *size_str);


void    show_map(WINDOW *map_w, char **game_arr)
{
    int i;
    int j;
    t_square *show_map;

    
    set_show_map_size(&show_map, game_arr[0]);
    i = START_MAP_Y;
    
    while (i < show_map->size_y + START_MAP_Y)
    {
        j = START_MAP_X;
        while (j < show_map->size_x + START_MAP_X)
        {
            mvwprintw(map_w, i, j, "%c", game_arr[i][j]);
            wrefresh(map_w);
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
    // fprintf(stderr, "[[[%s]]]", game_str);
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
        if (ft_strstr(line, "== X fin: "))
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







// t_square	*set_show_square(t_square *square)
// {
// 	set_show_size(&square);
// 	set_show_arr(&square);
// 	return (square);
// }

// void	read_filler(WINDOW *map_w)
// {
// 	t_square *map;
// 	t_square *piece;
// 	char my_sign;

// 	my_sign = set_show_sign();
	// map = set_show_square(map);
// 	piece = set_show_square(piece);
// 	mvwprintw(map_w, 2, 2, "map_size_x = %d map_size_y = %d\n p_size_x = %d p_size_y = %d\n", map->size_x, map->size_y, piece->size_x, piece->size_y);

// }

// char	set_show_sign()
// {
// 	char *line;
// 	char my_sign;

// 	line = NULL;
// 	get_next_line(0, &line);
// 	if (line[10] == '1')
// 		my_sign = 'O';
// 	else if (line[10] == '2')
// 		my_sign = 'X';
// 	ft_strdel(&line);
// 	return (my_sign);
// }
