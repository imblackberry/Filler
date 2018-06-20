/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:31:42 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/20 19:31:43 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_filler.h"

int	main(void)
{
	char **game_arr;

	game_arr = read_filler();
	show_filler(game_arr);
	ft_free_char_double_arr(&game_arr);
	return (0);
}
