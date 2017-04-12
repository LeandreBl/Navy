/*
** fill_player.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 00:30:34 2017 Léandre Blanchard
** Last update Thu Feb 23 15:45:34 2017 Léandre Blanchard
*/

#include "navy.h"

int		possible_line(char **map)
{
  map[0] = my_strdup("...##...\0");
  map[1] = my_strdup(".###....\0");
  map[2] = my_strdup("....####\0");
  map[3] = my_strdup(".#####..\0");
  map[4] = my_strdup("........\0");
  map[5] = my_strdup("........\0");
  map[6] = my_strdup("........\0");
  map[7] = my_strdup("........\0");
  return (0);
}

char		**create_bot_map(char **map)
{
  int		i;
  char		*tmp;
  int		j;
  int		k;

  if ((map = my_tab_alloc()) == NULL)
    return (NULL);
  i = 0;
  possible_line(map);
  while (i != 5000)
    {
      j = rand() % 8;
      k = rand() % 8;
      tmp = map[j];
      map[j] = map[k];
      map[k] = tmp;
      my_revstr(map[rand() % 8]);
      i++;
    }
  return (map);
}

int		fill_bot(t_player *bot)
{
  int		i;

  if ((bot->shots = my_tab_alloc()) == NULL)
    return (84);
  i = 0;
  while (i != 8)
    if ((bot->shots[i++] = my_strdup("........\0")) == NULL)
      return (84);
  bot->shots[8] = NULL;
  if ((bot->map = create_bot_map(bot->map)) == NULL)
    return (84);
  return (0);
}

int		fill_player(t_player *player)
{
  int		i;

  if ((player->shots = my_tab_alloc()) == NULL)
    {
      my_printf("%sMemory corrupted\n%s", BOLDRED, RESET);
      return (84);
    }
  i = 0;
  while (i != 8)
    if ((player->shots[i++] = my_strdup("........\0")) == NULL)
      {
	my_printf("%sMemory corrupted\n%s", BOLDRED, RESET);
	return (84);
      }
  player->shots[8] = NULL;
  if (multiplayer == 0)
    solo(player);
  if (multiplayer == 1)
    multi(player);
  return (0);
}
