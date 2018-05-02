/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:34:55 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/20 11:34:57 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main()
{
    t_game *game;

    game = NULL;
    start_game(&game);
//    if_error();
    
    free_game(&game);
  // system("leaks a.out");
    return (0);

}
//*********************************************DON`T NEED********************************
void    showarr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        printf("[%d] =\t|%s|\n", i, arr[i]);
        i++;
    }
}

void    set_game(t_game **game)
{
    save_file(game);
    (*game)->arrfile = ft_strsplit((*game)->file, '\n');
    set_player_sign(game);
    set_opponent_sign(game);
    set_map(game);
    set_piece(game);
}

void start_game(t_game **game)
{
    set_game_struct(game);
    set_game(game);
    put_piece(game);
	showarr((*game)->piece->arr);
	showarr((*game)->map->arr);

    
}

void    set_game_struct(t_game **game)
{
    (*game) = (t_game*)malloc(sizeof(t_game));
    if ((*game))
    {
        (*game)->my_sign = '\0';
        (*game)->opponent_sign = '\0';
        (*game)->file = NULL;
        (*game)->map = NULL;
        (*game)->piece = NULL;
        (*game)->valid_case = NULL;
    }
}

void    set_opponent_sign(t_game **game)
{
    if ((*game)->my_sign == 'x')
        (*game)->opponent_sign = 'o';
    else
        (*game)->opponent_sign = 'x';
}

void    set_player_sign(t_game **game)
{
    if ((*game)->arrfile[0][10] == '1')
        (*game)->my_sign = 'o';
    else if ((*game)->arrfile[0][10]== '2')
        (*game)->my_sign = 'x';
}

void    set_square_arr(char **arrfile, t_square **square, int start_x)
{
    int i;

    i = 0;
    (*square)->arr = (char**)malloc(sizeof(char*) * (*square)->size_y + 1);
    while (i < (*square)->size_y)
    {
        (*square)->arr[i] = ft_strsub(*(arrfile + i), start_x, (*square)->size_x);
        i++;
    }
    (*square)->arr[i] = 0;
}

void    set_square_size(t_square **square, char *size_str, int start_digital)
{
    int i;
    int size_x;
    int size_y;

    i = start_digital;
    size_y = ft_atoi(size_str + i);
    while(size_str[i] != ' ')
        i++;
    size_x = ft_atoi(size_str + i);
    (*square)->size_x = size_x;
    (*square)->size_y = size_y;
}

void    set_map(t_game **game)
{
    (*game)->map = (t_square*)malloc(sizeof(t_square));
    set_square_size(&(*game)->map, (*game)->arrfile[1], 8);
    set_square_arr((*game)->arrfile + 3, &(*game)->map, 4);
}

void    set_piece(t_game **game)
{
    int i;

    i = 3 + (*game)->map->size_y;
    (*game)->piece = (t_square*)malloc(sizeof(t_square));
    set_square_size(&(*game)->piece, (*game)->arrfile[i], 6);
    set_square_arr((*game)->arrfile + i + 1, &(*game)->piece, 0);
}
/* ************************************************************************** */

void    join_free(char **s1, char *s2)
{
    char	*save;

    save = *s1;
    *s1 = ft_strjoin(*s1, s2);
    ft_strdel(&save);
}

void    save_file(t_game **game)
{
    int gnl;
    char *line;
    int fd;//get out
    char *newline;

    fd = open("test.txt", O_RDONLY);
    newline = ft_strdup("\n");
    while((gnl = get_next_line(fd, &line)))
    {     
        if (!(*game)->file)
            (*game)->file = ft_strdup(line);
        else
            join_free(&(*game)->file, line);
        join_free(&(*game)->file, newline);
        ft_strdel(&line);
    }
    ft_strdel(&newline);
    ft_strdel(&line);
}

void    free_square(t_square **square)
{
    ft_free_double_arr(&(*square)->arr);
    (*square)->arr = 0;
    free(*square);
    *square = NULL;
}

void    free_game(t_game **game)
{
    ft_strdel(&(*game)->file);
    (*game)->file = NULL;
    ft_free_double_arr(&(*game)->arrfile);
    free_square(&(*game)->map);
    free_square(&(*game)->piece);
    free(*game);
    *game = NULL;
}





int check_sign(char checked_sign, char sign)
{
    if (checked_sign == sign || checked_sign == ft_toupper(sign))
        return (1);
    return (0);
}

void put_piece(t_game **game)
{
    int i;
    int j;

    i = j = 0;
    while (i < (*game)->map->size_y)
    {
        j = 0;
        while (j < (*game)->map->size_x)
        {
           if (check_sign((*game)->map->arr[i][j], (*game)->my_sign))
           {
               try_to_set_case(game, i, j);
               printf("i = %d, j = %d\n", i, j);
           }
            j++;
        }
        i++;
    }
}

t_case    *set_case_struct()
{
	t_case *valid_case;

	valid_case = (valid_case*)malloc(sizeof(t_case));
	

}

void    try_to_set_case(t_game **game, int i, int j)
{

}