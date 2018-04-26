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

#include "filler.h"

int main()
{
    int ret;

    ret = start_game();
   // system("leaks a.out");
    return (ret);
}

int start_game()
{
    int fd;
    t_game *game;

    game = NULL;
    fd = open("test.txt", O_RDONLY);
    game = set_game_struct(&game);
    set_sign(fd, &game);
    read_map(fd, &game);
}

t_game *set_game_struct(t_game *game)
{
    game = (t_game*)malloc(sizeof(t_game));

    if (game)
    {
        game->sign = '\0';
        game->map = NULL;
        game->piece = NULL;
    }
    return (game);
}

void set_player_sign(fd, t_game **game)
{
    int gnl;
    char *line;

    while ((gnl = get_next_line(fd, &line)))
    {
        if (ft_strstr(line, "vblokha"))
            break ;
        free(line);
    }
    if (ft_strchr(line, '1'))
        game->sign = 'o';
    else if (ft_strchr(line, '2'))
        game->sign = 'x';
    ft_strdel(&line);
}

int read_map(int fd)
{
    char *line;
    int gnl;
    char *file;
    char *save;

    file = NULL;
   
    printf("file = |%s|\n", file);
    return (0);
}


