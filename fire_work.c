/*
** fire_work.c for navy in /home/leandre
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Feb 22 16:49:17 2017 Léandre Blanchard
** Last update Wed Feb 22 17:15:35 2017 Léandre Blanchard
*/

#include "navy.h"

void		fire_work()
{
  static int		x = 50;
  static int		y = 100;
  static float		speed = 2;
  static float		gravity = 0.3;

  attron(COLOR_PAIR(CYELLOW) | A_BOLD);
  mvprintw(x, y, "*");
  speed -= gravity;
  x += speed;
  refresh();
}
