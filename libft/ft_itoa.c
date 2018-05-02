/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:06:20 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/20 14:44:14 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	howmuch(int n)
{
	size_t i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char		*rev(char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = s;
	while (*(p + 1) && *p++)
		;
	while (s < p && (*s += *p) && (*p = *s - *p) && (*s++ -= *p--))
		i++;
	return (s - i);
}

static char		*fill(long long int nbr, char *s, int z)
{
	size_t i;

	i = 0;
	while (nbr / 10 > 0)
	{
		s[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	s[i++] = nbr % 10 + '0';
	if (z < 0)
		s[i++] = '-';
	s[i] = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	long long int	nbr;
	long long int	z;

	nbr = (long long int)n;
	z = 0;
	len = howmuch(n);
	if (nbr < 0)
	{
		z = nbr;
		nbr = nbr * -1;
		len++;
	}
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	s = fill(nbr, s, z);
	s = rev(s);
	return (s);
}
