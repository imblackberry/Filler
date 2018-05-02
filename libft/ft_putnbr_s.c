/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:59:11 by vblokha           #+#    #+#             */
/*   Updated: 2018/02/12 18:59:13 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned long long int	ft_num_len(signed long long int n)
{
	size_t i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

unsigned long long int			ft_putnbr_s(signed long long int n)
{
	char					v;
	unsigned long long int	r_len;

	r_len = ft_num_len(n);
	if (n < -9000000000000000000)
	{
		write(1, "-", 1);
		write(1, "9", 1);
		n = -(n % 1000000000000000000);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr_s(n / 10);
	v = n % 10 + 48;
	write(1, &v, 1);
	return (r_len);
}
