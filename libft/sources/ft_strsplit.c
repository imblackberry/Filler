/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:21:30 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/20 16:18:09 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	k = 0;
	if (!s || !(split = (char **)malloc(sizeof(char*) * (ft_countwords(s, c)\
	+ 1))))
		return (0);
	while (s[i] && s[j] && k < ft_countwords(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		split[k++] = ft_strsub(s, i, j - i);
		i = j;
	}
	split[k] = 0;
	return (split);
}
