/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_double_int_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:30:29 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:35:21 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	**ft_new_double_int_arr(int size_x, int size_y)
{
	int **new;
	int i;
	int j;

	i = 0;
	j = 0;
	new = (int**)malloc(sizeof(int*) * size_y);
	while (i < size_y)
	{
		j = 0;
		new[i] = (int*)malloc(sizeof(int) * size_x);
		while (j < size_x)
		{
			new[i][j] = -1;
			j++;
		}
		i++;
	}
	return (new);
}
