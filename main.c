/*
** main.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 00:09:42 2017 Léandre Blanchard
** Last update Thu Feb 23 15:46:57 2017 Léandre Blanchard
*/

#include "navy.h"

int		main(void)
{
  t_player	*player;
  char		**map;
  int		return_value;

  srand(time(NULL));
  multiplayer = 3;
  clear();
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (84);
  if ((map = menu_map()) == NULL)
    {
      endwin();
      system("kill $(pgrep aplay)");
      return (0);
    }
  system("kill $(pgrep aplay)");
  if (boats_nb(map) != 14)
    map = NULL;
  player->map = map;
  if ((fill_player(player)) == 84)
    return_value = 84;
  if (multiplayer == 3)
    free_player(player, player->map);
  endwin();
  system("kill $(pgrep aplay)");
  my_printf(RESET);
  return (return_value);
}
