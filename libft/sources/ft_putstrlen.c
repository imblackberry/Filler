/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:08:35 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:45:44 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned long long int	ft_putstrlen(char *str, int len)
{
	int						i;
	unsigned long long int	r_len;

	r_len = 0;
	i = 0;
	if (len <= 0)
		return (r_len);
	while (str[i] && i < len)
		r_len = r_len + write(1, str + i++, 1);
	return (r_len);
}
