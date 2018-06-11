#include "libft.h"
void    ft_free_char_double_arr(char ***arr)
{
	int i;

	i = 0;
    if (!arr || !*arr)
        return ;
	while (arr[0][i])
	{
		ft_strdel(&arr[0][i]);
		i++;
	}
	free(arr[0]);
	arr[0] = NULL;
}
