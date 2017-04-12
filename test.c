/*
** test.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 20:57:51 2017 Léandre Blanchard
** Last update Sun Feb 19 15:08:40 2017 Léandre Blanchard
*/

#include "navy.h"

int		rec_shot(t_player *player, char *buffer)
{
  while (buffer[0] < 0 || buffer[0] > 7 || buffer[1] < 0 || buffer[1] > 7)
    {
      if (buffer[0] == 's' && buffer[1] == 'e' && buffer[2] == 'x')
	system("aplay -q sounds/ola.wav&");
      bzero(buffer, 3);
      read(player->new_fd, buffer, 3);
    }
  if (player->map[(int)buffer[0]][(int)buffer[1]] == '#')
    {
      write(player->new_fd, "OK\0", 3);
      player->map[(int)buffer[0]][(int)buffer[1]] = 'x';
      system("aplay -q sounds/hit.wav&");
    }
  else
    {
      write(player->new_fd, "KO\0", 3);
      player->map[(int)buffer[0]][(int)buffer[1]] = 'o';
      system("aplay -q sounds/plouf.wav&");
    }
  return (0);
}

int             win_lose(t_player *player)
{
  if (boats_nb(player->map) == 0)
    {
      you_lose_multi(player);
      return (0);
    }
  if (x_nb(player->shots) == 14)
    {
      you_win_multi(player);
      return (0);
    }
  return (1);
}

int		boats_nb(char **map)
{
  int		nb;
  int		i;
  int		j;

  i = 0;
  nb = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != 0)
	if (map[i][j++] == '#')
	  nb++;
      i++;
    }
  return (nb);
}

int		x_nb(char **map)
{
  int		nb;
  int		i;
  int		j;

  i = 0;
  nb = 0;
  while (map[i] != NULL)
    {
      j = 0;
      while (map[i][j] != 0)
	if (map[i][j++] == 'x')
	  nb++;
      i++;
    }
  return (nb);
}
