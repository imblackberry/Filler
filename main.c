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

void start_game(t_game **game)
{
    set_game_struct(game);



    save_file(game);
    (*game)->arrfile = ft_strsplit((*game)->file, '\n');
    set_player_sign(game);
    set_map(game);
    set_piece(game);



    
}

void    set_game_struct(t_game **game)
{
    (*game) = (t_game*)malloc(sizeof(t_game));
    if ((*game))
    {
        (*game)->sign = '\0';
        (*game)->file = NULL;
        (*game)->map = NULL;
        (*game)->piece = NULL;
    }
}

void    set_player_sign(t_game **game)
{
    if ((*game)->arrfile[0][10] == '1')
        (*game)->sign = 'o';
    else if ((*game)->arrfile[0][10]== '2')
        (*game)->sign = 'x';
}

void    set_square_arr(char **arrfile, t_square **square, int start_x)
{
    int i;
    int j;

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
    showarr((*game)->piece->arr);
}
/* ************************************************************************** */

void    join_free(char **s1, char *s2)
{
    char *save;

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

