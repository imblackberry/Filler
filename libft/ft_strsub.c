/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:46:06 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/19 18:08:47 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s,
	unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return (0);
	i = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (0);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
