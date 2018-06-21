/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:10:18 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/20 15:17:36 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	status;

	status = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			status = 0;
		else if (status == 0)
		{
			status = 1;
			count++;
		}
		s++;
	}
	return (count);
}
