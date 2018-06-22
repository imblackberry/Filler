/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:54:19 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/26 12:54:21 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void		start_game(t_game **game);
void		set_game_struct(t_game **game);
void		set_opponent_sign(t_game **game);
int		set_player_sign(t_game **game);
int			set_game(t_game **game);
int			put_piece_everywhere(t_game **game);
void		search_one_xy_case(t_game **game);
void		set_result(t_game **game, int min_distance);
void		show_turn_result(t_game *game);
void		set_map(t_game **game);
void		set_piece(t_game **game);
void		set_square_arr(char **arrfile, t_square **square, int start_x);
void		set_square_size(t_square **square, char *size_str,
int start_digital);
void		set_distance_map(t_game **game);
int			save_file(t_game **game);
t_case		*set_case_struct(int y, int x);
void		set_valid_case(t_game **game, int map_i, int map_j);
int			search_valid_cases(t_game **game, int map_i, int map_j);
int			check_sign(t_game *game, char map_sign, char piece_sign);
int			min_distance_in_piece(int j_map, int i_map, t_game *game);
void		set_valid_case_distance(t_game *game);
void		set_each_distance(t_game **game);
void		set_opponent_distance(t_game **game);
int			search_minimum_distance(t_case	*valid_case);
int			can_put_distance(int **distance_map, int size_x, int size_y);
int			point_exist_in_map(t_square *map, int i, int j);
void		surround_the_point(t_square *map, int ***distance_map,
int y, int x);
void		search_surrounding_point(t_game **game, int surround_it);
void		free_square(t_square **square);
void		free_case(t_case **valid_case);
void		free_game(t_game **game);
void		free_game_my_turn(t_game **game);
int			read_to_end(char **line, int *to_end, int *i);
void		assign_null(int *a, int *b, int *c, int *d);

#endif
