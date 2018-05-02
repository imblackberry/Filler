/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:50:40 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/20 14:18:30 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst,
	const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	k = ft_strlen(dst);
	while (dst[i])
		i++;
	while (src[j] && i < dstsize - 1 && dstsize != 0)
		dst[i++] = src[j++];
	dst[i] = '\0';
	if (dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	return (k + ft_strlen(src));
}
