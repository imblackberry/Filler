#include "get_next_line.h"

static t_file *new_file(int fd)
{
  t_file *file;

  file = (t_file*)malloc(sizeof(t_file));
  if (!file)
    return (NULL);
  file->fd = fd;
  file->buf = ft_strnew(BUFF_SIZE);
  if (!file->buf)
    {
      free(file);
      return (NULL);
    }
  file->next = NULL;
  return (file);
}

static int save_line(char *buf, char **line)
{
  unsigned int i;
  char *trash;
  char *line_part;

  i = 0;
  while (buf[i] && buf[i] != '\n')
    i++;
  trash = *line;
  if (!(line_part = ft_strnew(i)))
    {
      free(trash);
      return (-1);
    }
  line_part = ft_strncpy(line_part, buf, i);
  *line = ft_strjoin(*line, line_part);
  free(trash);
  free(line_part);
  return (buf[i] == '\n');
}

static t_file*get_file(t_file **head, int fd)
{
  t_file *target;

  if (!*head && !(*head = new_file(fd)))
    return (NULL);
  target = *head;
  while (target->next && target->fd != fd)
    target = target->next;
  if (target->fd != fd)
    {
      target->next = new_file(fd);
      if (!(target = target->next))
	return (NULL);
    }
  return (target);
}

int get_next_line(const int fd, char **line)
{
  static t_file *head;
  t_file *cur;
  int rd_flag;
  int sv_flag;
  char *tmp;

  if (!line || !(*line = ft_strnew(1)))
    return (-1);
  if (!(cur = get_file(&head, fd)))
    return (-1);
  rd_flag = 1;
  while (!(sv_flag = save_line(cur->buf, line)) && rd_flag)
    {
      ft_strclr(cur->buf);
      rd_flag = read(fd, cur->buf, BUFF_SIZE);
      if (rd_flag == -1 || sv_flag == -1)
	return (-1);
    }
  if ((tmp = ft_strchr(cur->buf, '\n')))
    {
      ft_memmove(cur->buf, tmp + 1, ft_strlen(tmp + 1));
      ft_strclr(cur->buf + ft_strlen(tmp + 1));
    }
  return (rd_flag || sv_flag || ft_strlen(*line) ? 1 : 0);
}
