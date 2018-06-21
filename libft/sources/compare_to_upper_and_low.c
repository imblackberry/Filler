/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_to_upper_and_low.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:51:44 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/05 17:52:30 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	compare_to_upper_and_low(char c, char lower_virsion)
{
	return (c == lower_virsion || c == ft_toupper(lower_virsion));
}
