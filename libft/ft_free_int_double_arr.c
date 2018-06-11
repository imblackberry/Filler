/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_double_arr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:17:09 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:17:10 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_int_double_arr(int ***arr, int size_y)
{
	int i;

	i = 0;
	if (*arr != NULL)
		return ;
	while (i < size_y)
	 	free(arr[0][i++]);
	free(arr[0]);
	arr[0] = NULL;
}