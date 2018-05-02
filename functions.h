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

#ifndef FUNCIONS_H
#define FUNCIONS_H

void    start_game(t_game **game);
void    set_game_struct(t_game **game);
void    set_player_sign(t_game **game);
void    save_file(t_game **game);
void    free_game(t_game **game);
void    join_free(char **s1, char *s2);
void    free_game(t_game **game);
void    set_map(t_game **game);
void    set_piece(t_game **game);
void    set_opponent_sign(t_game **game);
void    try_to_set_case(t_game **game, int i, int j);
void put_piece_everywhere(t_game **game);
int search_valid_cases(t_game **game, int map_i, int map_j);
void set_valid_case(t_game **game, int map_i, int map_j);

#endif