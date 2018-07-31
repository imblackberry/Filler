#include "show_filler.h"

int main(void)
{
  char **game_arr;

  game_arr = read_filler();
  show_filler(game_arr);
  ft_free_char_double_arr(&game_arr);
  return (0);
}
