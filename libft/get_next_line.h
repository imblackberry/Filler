#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1024

typedef struct s_file
{
  int fd;
  char *buf;
  struct s_file*next;
} t_file;

int get_next_line(const int fd, char **line);

#endif
