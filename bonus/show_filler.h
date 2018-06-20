/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_filler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:06:07 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/20 20:06:08 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_FILLER_H
# define SHOW_FILLER_H

# include <ncurses.h>
# include "show_struct.h"
# include "../libft/libft.h"
# define O_SCORE_LINE 4
# define X_SCORE_LINE 6
# define SCORE_X_SIZE 28
# define SCORE_Y_SIZE 9
# define X_COLOR_PAIR 1
# define O_COLOR_PAIR 2
# define DOT_COLOR_PAIR 3
# define START_MAP_Y 2
# define START_MAP_X 4

void	sleep_and_refresh_w(WINDOW **window, int seconds);
int		search_new_map_position(char **game_arr);
void	set_windows(t_square *show_map, WINDOW **map_w, WINDOW **score_w);
void	set_results(char **game_arr, int *o_result, int *x_result);
void	show_who_is_who(WINDOW **score_w, int o_result, int x_result);
int		show_score(WINDOW **score_w, char **game_arr);
void	show_filler(char **game_arr);
void	show_character(WINDOW *map_w, int i, int j, char c);
void	show_game_map(WINDOW *map_w, char **game_arr, t_square *show_map);
void	show_filler_in_windows(char **game_arr, t_square *show_map);
void	set_show_map_size(t_square **show_map, char *size_str);
char	**read_filler();
char	*save_show_file();
void	save_game_file(char **file, char *line);

#endif
