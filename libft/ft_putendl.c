/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:23:08 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/09 17:12:10 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long long int	ft_putendl(char const *s)
{
	unsigned long long int r_len;

	r_len = 0;
	while (*s)
		r_len = r_len + write(1, s++, 1);
	r_len = r_len + write(1, "\n", 1);
	return (r_len);
}
