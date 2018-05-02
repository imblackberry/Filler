/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:59:36 by vblokha           #+#    #+#             */
/*   Updated: 2018/02/12 18:59:37 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned long long int	ft_num_len(unsigned long long int n)
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

unsigned long long int			ft_putnbr_u(unsigned long long int n)
{
	char					v;
	unsigned long long int	r_len;

	r_len = ft_num_len(n);
	if (n / 10 > 0)
		ft_putnbr_u(n / 10);
	v = n % 10 + 48;
	write(1, &v, 1);
	return (r_len);
}
