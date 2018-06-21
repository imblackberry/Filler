/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:49:31 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/20 13:37:16 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	k;

	k = (unsigned char)c;
	p = (unsigned char*)s;
	while (n && n--)
	{
		if (*p == k)
			return (p);
		p++;
	}
	return (0);
}
