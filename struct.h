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
# define STRUCT_H

typedef struct		s_square
{
	int		size_x;
	int		size_y;
	char	**arr;
}					t_square;

typedef struct		s_case
{
	int				x;
	int				y;
	int				distance;
	struct s_case	*next;
}					t_case;

typedef struct		s_game
{
	char		my_sign;
	char		opponent_sign;
	char		*file;
	char		**arrfile;
	int			**distance_map;
	t_square	*map;
	t_square	*piece;
	t_case		*valid_case;
	int			x;
	int			y;
}					t_game;

#endif
