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


// int main()
// {
//     t_game *game;

//     game = NULL;
//     start_game(&game);
//     free_game(&game);
//     return (0);

// }
//*********************************************DON`T NEED********************************










void    showarr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        fprintf(stderr, "\t\t\t\t\t\t\t\t\t\t\t\t[%d] =\t|%s|\n", i, arr[i]);
        i++;
    }
}












// int    set_game(t_game **game)
// {
// 	int ret;

// 	ret = 0;
//     if (save_file(game) < 0)
// 		return (-1);
//     (*game)->arrfile = ft_strsplit((*game)->file, '\n');
//     set_map(game);
//     set_piece(game);
// 	return (ret);
// }

// void    free_square(t_square **square)
// {
// 	if (!square || !*square)
//         return ;
//     ft_free_char_double_arr(&(*square)->arr);
// 	(*square)->arr = NULL;
//     (*square)->size_x = 0;
//     (*square)->size_y = 0;
//     free(*square);
//     (*square) = NULL;
// }

// void	free_case(t_case **valid_case)
// {
// 	t_case *tmp;

// 	if (*valid_case == NULL)
// 		return ;
// 	while ((*valid_case) != NULL)
// 	{
// 		tmp = (*valid_case)->next;
// 		free(*valid_case);
// 		*valid_case = NULL;
// 		*valid_case = tmp;
// 	}
// }

// void	ft_free_int_double_arr(int ***arr, int size_y)
// {
// 	int i;

// 	i = 0;
// 	if (*arr != NULL)
// 		return ;
// 	while (i < size_y)
// 	 	free(arr[0][i++]);
// 	free(arr[0]);
// 	arr[0] = NULL;
// }

// void	free_game_my_turn(t_game **game)
// {
// 	t_square *map;

//     // if (!(*game)->file || !(*game)->map || !(*game)->piece)
//     //     return ;
// 	map = (*game)->map;
// 	ft_strdel(&(*game)->file);
//     ft_free_char_double_arr(&(*game)->arrfile);
// 	if ((*game)->map && (*game)->map->size_x && (*game)->map->size_y)
// 		ft_free_int_double_arr(&(*game)->distance_map, map->size_y);
//     free_square(&(*game)->map);
//     free_square(&(*game)->piece);
// 	free_case(&(*game)->valid_case);//DO
// 	(*game)->x = 0;
//     (*game)->y = 0;
// }

// void    show_turn_result(t_game *game)
// {
//     ft_putnbr(game->y);
// 	ft_putchar(' ');
// 	ft_putnbr(game->x);
// 	ft_putchar('\n');
// }

// void	start_game(t_game **game)
// {
//     set_game_struct(game);
// 	set_player_sign(game);
//     set_opponent_sign(game);
// 	while (set_game(game) >= 0)
// 	{
// 		if ((put_piece_everywhere(game)) < 0)
// 			break ;
// 		search_one_xy_case(game);
//         show_turn_result(*game);
// 		free_game_my_turn(game);
// 	}
//     show_turn_result(*game);
//     free_game_my_turn(game);
// }

// void    set_game_struct(t_game **game)
// {
//     (*game) = (t_game*)malloc(sizeof(t_game));
//     if ((*game))
//     {
//         (*game)->my_sign = '\0';
//         (*game)->opponent_sign = '\0';
//         (*game)->file = NULL;
// 		(*game)->arrfile = NULL;
// 		(*game)->distance_map = NULL;
//         (*game)->map = NULL;
//         (*game)->piece = NULL;
//         (*game)->valid_case = NULL;
//         (*game)->x = 0;
//         (*game)->y = 0;
//     }
// }

// void    set_opponent_sign(t_game **game)
// {
//     if ((*game)->my_sign == 'X')
//         (*game)->opponent_sign = 'O';
//     else
//         (*game)->opponent_sign = 'X';
// }

// void    set_player_sign(t_game **game)
// {
// 	char *line;

// 	line = NULL;
// 	get_next_line(0, &line);
//     if (line[10] == '1')
//         (*game)->my_sign = 'O';
//     else if (line[10] == '2')
//         (*game)->my_sign = 'X';
// 	ft_strdel(&line);
// }

// void    set_square_arr(char **arrfile, t_square **square, int start_x)
// {
//     int i;

//     i = 0;
//     (*square)->arr = (char**)malloc(sizeof(char*) * ((*square)->size_y + 1));
//     while (i < (*square)->size_y)
//     {
//         (*square)->arr[i] = ft_strsub(*(arrfile + i), start_x, (*square)->size_x);
//         i++;
//     }
//     (*square)->arr[i] = 0;
// }

// void    set_square_size(t_square **square, char *size_str, int start_digital)
// {
//     int i;
//     int size_x;
//     int size_y;

//     i = start_digital;
//     size_y = ft_atoi(size_str + i);
//     while(size_str[i] != ' ')
//         i++;
//     size_x = ft_atoi(size_str + i);
//     (*square)->size_x = size_x;
//     (*square)->size_y = size_y;
// }

// void    set_map(t_game **game)
// {
//         // fprintf(stderr, "\t\t\t\t\t\tSHOW ME FILE IN SET_MAP \n[%s]\n", (*game)->file);
//     (*game)->map = (t_square*)malloc(sizeof(t_square));
//     set_square_size(&(*game)->map, (*game)->arrfile[0], PLATEAU + 1);
//     set_square_arr((*game)->arrfile + START_MAP_Y, &(*game)->map, START_MAP_X);
// }

// void    set_piece(t_game **game)
// {
//     int i;

//     i = START_MAP_Y + (*game)->map->size_y;
//     (*game)->piece = (t_square*)malloc(sizeof(t_square));
//     set_square_size(&(*game)->piece, (*game)->arrfile[i], PIECE + 1);
//     set_square_arr((*game)->arrfile + i + 1, &(*game)->piece, 0);
// }
/* ************************************************************************** */

// void    ft_join_free(char **s1, char *s2)
// {
//     char	*save;

//     save = *s1;
//     *s1 = ft_strjoin(*s1, s2);
//     ft_strdel(&save);
// }

// int    save_file(t_game **game)
// {
//     char *line;
//     int ret;
//     char *newline;
// 	int i;
// 	int to_end;
	
// 	to_end = 0;
// 	i = 0;
// 	ret = 1;
// 	line = NULL;
//     newline = ft_strdup("\n");
//     while (i < to_end || !to_end)
//     {   
// 		if (get_next_line(0, &line) <= 0 || (!ft_strcmp("", line) && !to_end))
//         {
// 			ret = -1;
//             break ;
//         }
// 		if (ft_strstr(line, "Piece"))
// 			to_end = ft_atoi(line + PIECE);
// 		else if (to_end)
// 			i++;
//         if (!(*game)->file)
//             (*game)->file = ft_strdup(line);
//         else
//             ft_join_free(&(*game)->file, line);
// 		ft_join_free(&(*game)->file, newline);
//         ft_strdel(&line);
//     }
//     ft_strdel(&newline);
//     ft_strdel(&line);
// 	return (ret);
// }

// void    free_game(t_game **game)
// {
//     free(*game);
//     *game = NULL;
// }

// int put_piece_everywhere(t_game **game)
// {
//     int map_i;
//     int map_j;

//     map_i = map_j = 0;
//     while (map_i <= (*game)->map->size_y - (*game)->piece->size_y)
//     {
//         map_j = 0;
//         while (map_j <= (*game)->map->size_x - (*game)->piece->size_x)
//         {
// 			if (search_valid_cases(game, map_i, map_j))
//                 set_valid_case(game, map_i, map_j);
//         	map_j++;
// 		}
//     	map_i++;
//     }
// 	if (!(*game)->valid_case)
// 		return (-1);
// 	return (0);
// }

// t_case    *set_case_struct(int y, int x)
// {
// 	t_case *valid_case;

// 	valid_case = (t_case*)malloc(sizeof(t_case));
// 	if (valid_case)
// 	{
// 		valid_case->x = x;
// 		valid_case->y = y;
// 		valid_case->distance = 0;
// 		valid_case->next = NULL;
// 	}
// 	return (valid_case);
// }

// int check_sign(t_game *game, char map_sign, char piece_sign)
// {
//     if (piece_sign == '*' && map_sign == game->my_sign)
//         return (1);
//     else if (piece_sign == '*' && map_sign == game->opponent_sign)
//         return (-1);
//     return (0);
// }
// p m
// . . + 0
// . o + 0
// . x + 0
// * . + 0
// * o (only one case must be) 1
// * x (no) -1
// void set_valid_case(t_game **game, int map_i, int map_j)
// {
//     t_case *new_case;
//     t_case *tmp;

//     new_case = set_case_struct(map_i, map_j);
//     if (!(*game)->valid_case)
//         (*game)->valid_case = new_case;
//     else
//     {
//         tmp = (*game)->valid_case;
//         while (tmp->next)
//             tmp = tmp->next;
//          tmp->next = new_case;
//     }
// }

// int search_valid_cases(t_game **game, int map_i, int map_j)
// {
//     int i;
// 	int j;
// 	int opp_imposition;
//     int my_imposition;

//     i = j = opp_imposition = my_imposition = 0;
//     while (i < (*game)->piece->size_y)
// 	{
//         map_j -= j;
// 		j = 0;
// 		while(j < (*game)->piece->size_x)
// 		{
// 			if (check_sign(*game, (*game)->map->arr[map_i][map_j], (*game)->piece->arr[i][j]) == 1)
// 				my_imposition++;
//             else if (check_sign(*game, (*game)->map->arr[map_i][map_j], (*game)->piece->arr[i][j]) == -1)
//                 opp_imposition++;
// 			j++;
//             map_j++;
// 		}
// 		i++;
//         map_i++;
// 	}
//     if (my_imposition == 1 && opp_imposition == 0)
//         return (1);
//     return (0);
// }
/* ************************************************************************** */

