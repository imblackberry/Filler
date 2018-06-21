/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:18:31 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/09 17:10:38 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long long int	ft_putstr(char const *s)
{
	unsigned long long int r_len;

	r_len = 0;
	while (*s)
		r_len = r_len + write(1, s++, 1);
	return (r_len);
}
