/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:33:14 by vblokha           #+#    #+#             */
/*   Updated: 2017/12/07 16:33:19 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int				ft_line_size(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void			ft_lstaddfirst(t_mylst **head, int fd, t_mylst **lst)
{
	t_mylst *first;

	while ((*head) && (*head)->fd != fd)
		(*head) = (*head)->next;
	if ((*head) == NULL)
	{
		first = (t_mylst*)malloc(sizeof(t_mylst));
		first->content = ft_strdup("");
		first->fd = fd;
		first->next = NULL;
		if ((*lst) == NULL)
			(*lst) = first;
		else
		{
			first->next = (*lst);
			(*lst) = first;
		}
		(*head) = *lst;
	}
}

void			ft_tail(t_struct p, t_mylst **head)
{
	if (p.k == 0)
	{
		p.str = (*head)->content;
		if (ft_strchr((*head)->content, '\n') != 0)
			(*head)->content = ft_strdup(ft_strchr((*head)->content, '\n') + 1);
		else
			(*head)->content = ft_strdup("");
		free(p.str);
		p.str = NULL;
	}
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_mylst	*lst = NULL;
	t_mylst			*head;
	t_struct		p;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	head = lst;
	ft_lstaddfirst(&head, fd, &lst);
	while ((p.ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[p.ret] = '\0';
		p.str = head->content;
		head->content = ft_strjoin(head->content, buf);
		free(p.str);
		p.str = NULL;
		if (ft_strchr(head->content, '\n'))
			break ;
	}
	*line = ft_strsub(head->content, 0, ft_line_size(head->content));
	p.k = ft_strlen(head->content) == 0 ? 1 : 0;
	ft_tail(p, &head);
	if (p.ret == 0 && p.k == 1)
		return (0);
	return (1);
}
