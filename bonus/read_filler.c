#include "show_filler.h"

char    **read_filler(void)
{
  char **game_arr;
  char *game_str;

  game_str = save_show_file();
  game_arr = ft_strsplit(game_str, '\n');
  ft_strdel(&game_str);
  return (game_arr);
}

char    *save_show_file(void)
{
  char *line;
  char *file;

  file = NULL;
  line = NULL;
  while (get_next_line(0, &line) > 0)
    {
      save_game_file(&file, line);
      if (ft_strstr(line, "== X fin:"))
	break ;
      ft_strdel(&line);
    }
  ft_strdel(&line);
  return (file);
}

void    save_game_file(char **file, char *line)
{
  char *newline;

  newline = ft_strdup("\n");
  if (*file == NULL)
    *file = ft_strdup(line);
  else
    ft_join_free(file, line);
  ft_join_free(file, newline);
  ft_strdel(&newline);
}

int search_new_map_position(char **game_arr)
{
  int i;

  i = 0;
  while (game_arr[i] != NULL && !ft_strstr(game_arr[i], "Plateau")
	 && !ft_strstr(game_arr[i], "== O fin"))
    i++;
  return (i);
}

void    set_show_map_size(t_square **show_map, char *size_str)
{
  int i;

  i = 0;
  (*show_map) = (t_square*)malloc(sizeof(t_square));
  while (!ft_isdigit(size_str[i]))
    i++;
  (*show_map)->size_y = ft_atoi(size_str + i);
  while (ft_isdigit(size_str[i]))
    i++;
  (*show_map)->size_x = ft_atoi(size_str + i);
  (*show_map)->arr = NULL;
}
