#include "libft.h"
void    ft_free_double_arr(char ***arr)
{
  int i;

  i = 0;
  while (arr[0][i])
    {
      ft_strdel(&arr[0][i]);
      i++;
    }
  free(arr[0]);
}
