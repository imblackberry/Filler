/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:47:44 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/13 11:41:41 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int	ft_putendl_fd(char const *s, int fd)
{
	unsigned long long int r_len;

	r_len = 0;
	r_len = r_len + write(fd, s, ft_strlen(s));
	r_len = r_len + write(fd, "\n", 1);
	return (r_len);
}
