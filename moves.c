/*
** moves.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 14:22:12 2017 Léandre Blanchard
** Last update Wed Feb 22 22:03:41 2017 Léandre Blanchard
*/

#include "navy.h"

int		move_arrow_2(int a, int i)
{
  if (i == KEY_UP || i == KEY_DOWN)
    system("aplay -q sounds/bip.wav&");
  if (i == KEY_UP)
    a--;
  if (i == KEY_DOWN)
    a++;
  if (a > 1)
    a = 0;
  if (a < 0)
    a = 1;
  return (a);
}

int		move_arrow(int a, int i)
{
  if (i == KEY_UP || i == KEY_DOWN)
    system("aplay -q sounds/bip.wav&");
  if (i == KEY_UP)
    a--;
  if (i == KEY_DOWN)
    a++;
  if (a > 3)
    a = 0;
  if (a < 0)
    a = 3;
  return (a);
}

t_xy		move_pos_arrow(int i, t_xy pos)
{
  if (i == KEY_UP || i == KEY_DOWN || i == KEY_LEFT || i == KEY_RIGHT)
    system("aplay -q sounds/bip.wav&");
  if (i == KEY_UP)
    pos.i--;
  if (i == KEY_DOWN)
    pos.i++;
  if (i == KEY_LEFT)
    pos.j--;
  if (i == KEY_RIGHT)
    pos.j++;
  if (i == KEY_END)
    pos.j = 7;
  if (i == 262)
    pos.j = 0;
  if (pos.i < 0)
    pos.i = 7;
  if (pos.i > 7)
    pos.i = 0;
  if (pos.j < 0)
    pos.j = 7;
  if (pos.j > 7)
    pos.j = 0;
  return (pos);
}

void		insert_delete(t_xy pos, char **map, int action)
{
  int		i;
  int		j;
  char		*sound;

  if ((sound = my_strdup("aplay -q sounds/craft_0.wav&")) == NULL)
    {
      my_printf("Out of memory\n");
      return;
    }
  sound[22] = 49 + rand() % 3;
  i = pos.i;
  j = pos.j;
  if (action == 32 && boats_nb(map) < 14)
    {
      system(sound);
      map[i][j] = '#';
    }
  if (action == 'd')
    map[i][j] = '.';
  free(sound);
}
