/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:38:57 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/20 16:06:22 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s,
					char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (0);
	while (s[i])
		i++;
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
