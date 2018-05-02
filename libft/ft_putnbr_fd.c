/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:00:59 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/13 14:26:36 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	ft_putnbr_fd(int n, int fd)
{
	char					v;
	unsigned long long int	r_len;

	r_len = 0;
	if (n == -2147483648)
	{
		r_len = r_len + write(fd, "-", 1);
		r_len = r_len + write(fd, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		r_len = r_len + write(fd, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	v = n % 10 + 48;
	r_len = r_len + write(fd, &v, 1);
	return (r_len);
}
