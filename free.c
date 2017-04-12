/*
** free.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 00:27:51 2017 Léandre Blanchard
** Last update Thu Feb  2 22:02:52 2017 Léandre Blanchard
*/

#include "navy.h"

void		free_player(t_player *player, char **map)
{
  if (map != NULL)
    {
      free_tab(player->shots);
      free_tab(player->map);
      if (multiplayer == 1)
	free(player->ip);
    }
  free(player);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}
