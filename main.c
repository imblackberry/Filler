# include "libft/includes/libft.h"

int main()
{
	char *line;

	ft_putstr("Vika\n");
	get_next_line(0, &line);
	ft_putstr(line);
	free(line);
}
