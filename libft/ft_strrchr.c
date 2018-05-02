/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:07:00 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/19 15:29:57 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*p;
	int				l;

	l = 0;
	p = (unsigned char *)s;
	while (p[l])
		l++;
	while (p[l] != c)
	{
		if (!l)
			return (0);
		l--;
	}
	return ((char*)(p + l));
}
