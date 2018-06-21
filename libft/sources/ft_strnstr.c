/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:15:13 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/18 18:44:05 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little,
	size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char*)big);
	while (big[i] && ft_strlen(big) >= ft_strlen(little))
	{
		while (little[j] == big[i] && little[j] && big[i] && i < len)
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
