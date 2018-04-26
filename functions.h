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

#include "struct.h"

int start_game();
t_game *set_game_struct(t_game *game);
void set_player_sign(fd, t_game **game);
int read_map(int fd);

#endif