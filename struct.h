/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:35:29 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/26 13:35:30 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_game
{
    char sign;
    t_map *map;
    t_piece *piece;
}               t_game;

typedef struct s_map
{
    int x;
    int y;
}               t_map;

typedef struct s_piece
{
    int x;
    int y;
}               t_piece;

#endif