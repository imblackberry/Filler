/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:13:49 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:14:38 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_join_free(char **s1, char *s2)
{
	char *save;

	save = *s1;
	*s1 = ft_strjoin(*s1, s2);
	ft_strdel(&save);
}
