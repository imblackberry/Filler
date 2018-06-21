/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_double_arr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:48:48 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/12 19:48:51 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_char_double_arr(char ***arr)
{
	int i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (arr[0][i])
	{
		ft_strdel(&arr[0][i]);
		i++;
	}
	free(arr[0]);
	arr[0] = NULL;
}
