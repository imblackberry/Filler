#include <ncurses.h>
#include "libft/libft.h"
# include "filler.h"

char	**read_filler();
char	set_show_sign();
void    show_game_map(WINDOW *map_w, char **game_arr, t_square *show_map);
void	set_show_map_size(t_square **map, char *size_str);

int search_new_map_position(char **game_arr)
{
	int i;

	i = 0;
	while(game_arr[i] != NULL && !ft_strstr(game_arr[i], "Plateau"))
            i++;
	return (i);
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
	map_w = newwin(show_map->size_y + (START_MAP_Y * 2), show_map->size_x + (START_MAP_X * 2), 0, 0);
	score_w = newwin(5, 21, 0, show_map->size_x + (START_MAP_X * 3));
	box(map_w, '*', '*');
    wrefresh(map_w);
	box(score_w, '*', '*');
    wrefresh(score_w);
	while(game_arr[i])
	{	
		i += search_new_map_position(game_arr + i);
		if (game_arr[i] == NULL)
		{
			mvwprintw(score_w, 2, 10, "SCORE");
			wrefresh(score_w);
			usleep(3000000);
			wrefresh(map_w);
			break ;
		}
		show_game_map(map_w, game_arr + i, show_map);
		usleep(30000);
        wrefresh(map_w);
        i++;
	}
    ft_free_char_double_arr(&game_arr);
    getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    endwin();
	// system("leaks a.out");
    return (0);
}
char    *save_show_file();
void    save_game_file(char **file, char *line);


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
            mvwprintw(map_w, i, j, "%c", game_arr[i][j]);
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
