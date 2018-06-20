/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:10:50 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/14 15:10:51 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>

int main()
{
	char *line;
	char	buff[10];
	// int fd;

	line = NULL;
	// fd = open("test.txt", O_RDONLY);
	// printf("before a loop\n");
	while (read(0, buff, 10))//get_next_line(0, &line))
	{
		write(1, "|", 1);
		write(1, buff, 10);
		write(1, "|\n", 2);
		// printf("in the loop\n");
		// printf("|%s|\n", line);
		// free(line);
	}
	// printf("after the loop\n");
	// close(fd);
	return (0);
}