/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:41:03 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/09 17:14:25 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long long int	ft_putnbr(int n)
{
	char					v;
	unsigned long long int	r_len;

	r_len = 0;
	if (n == -2147483648)
	{
		r_len = r_len + write(1, "-", 1);
		r_len = r_len + write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		r_len = r_len + write(1, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	v = n % 10 + 48;
	r_len = r_len + write(1, &v, 1);
	return (r_len);
}
