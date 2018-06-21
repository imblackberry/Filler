/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:04:29 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/21 14:34:04 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstaddend(t_list *lst1, t_list *lst2)
{
	t_list *tmp;

	tmp = lst1;
	while (lst1->next)
		lst1 = lst1->next;
	lst1->next = lst2;
	return (tmp);
}
