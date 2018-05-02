/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:24:06 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/20 12:45:38 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	char	*new;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	if (!(new = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	ft_bzero(new, 2);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	k = ft_strlen(s);
	if (i == k || !k)
		return (new);
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t' || !s[k])
		k--;
	if (!(new = (char*)malloc(sizeof(char) * (k - i + 2))))
		return (NULL);
	ft_bzero(new, k - i + 2);
	return (ft_strncpy(new, s + i, k - i + 1));
}
