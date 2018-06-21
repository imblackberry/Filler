/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:03:24 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/18 18:16:58 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char*)big);
	while (big[i] && ft_strlen(big) >= ft_strlen(little))
	{
		while (little[j] == big[i] && big[i] && little[j])
		{
			if (little[j + 1] == '\0')
				return ((char*)(big + i - j));
			if (little[j + 1] != big[i + 1])
			{
				i = i - j;
				j = 0;
				break ;
			}
			i++;
			j++;
		}
		i++;
	}
	return (0);
}
