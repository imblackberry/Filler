/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:34:55 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/20 11:34:57 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <stdio.h>//DEEEEEEEEEEEEEEEL
#include "ft_printf/libft/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>//-----
#include <errno.h>//?????
#include <unistd.h>//??????

#include "filler.h"

int my_reading(int fd)
{
    char *line;
    int gnl;
    char *file;

    file = NULL;
    while ((gnl = get_next_line(fd, &line)))
    {
        if (file)
            file = ft_strjoin(file, line);
        else
            file = ft_strdup(line);
 //printf("line = |%s|\n", line);
       file = ft_strcat(file, ft_strdup("\n"));
       // printf("file = |%s|\n", file);   
    }
//    printf("file = |%s|\n", file);
    return (0);
}
int main()
{
    //char *file;
    //file = NULL;
    int fd;

    fd = open("test.txt", O_RDONLY);
    my_reading(fd);

    // file = ft_strcat(ft_strdup(file) , ft_strdup("kykyky"));
    // printf("file = |%s|\n", file);
    return (0);
}