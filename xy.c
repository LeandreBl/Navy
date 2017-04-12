/*
** xy.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb  3 19:00:06 2017 Léandre Blanchard
** Last update Fri Feb  3 19:02:15 2017 Léandre Blanchard
*/

#include "navy.h"

t_xy		init_xy(int i, int j)
{
  t_xy		xy;

  xy.i = i;
  xy.j = j;
  return (xy);
}
