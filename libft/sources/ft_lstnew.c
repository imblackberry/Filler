/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:45:31 by vblokha           #+#    #+#             */
/*   Updated: 2017/11/21 14:58:18 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*data;

	list = NULL;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		data = (void*)malloc(sizeof(content_size));
		list->content = data;
		if (!list->content)
		{
			free(list);
			return (0);
		}
		list->content_size = content_size;
		ft_memcpy(list->content, content, content_size);
	}
	list->next = NULL;
	return (list);
}
