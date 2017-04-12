/*
** quick_display_2.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb  3 18:16:36 2017 Léandre Blanchard
** Last update Wed Feb  8 16:38:11 2017 Léandre Blanchard
*/

#include "navy.h"

void		turn()
{
  attron(COLOR_PAIR(CRED) | A_BOLD);
  mvprintw(2, COLS / 2 - 8, "[Ennemy turn.  ]");
  refresh();
  usleep(100000);
  mvprintw(2, COLS / 2 - 8, "[Ennemy turn.. ]");
  refresh();
  usleep(100000);
  mvprintw(2, COLS / 2 - 8, "[Ennemy turn...]");
  refresh();
  usleep(100000);
}

void		solo_display(t_player *player, t_xy pos)
{
  clear();
  display_my(player->map);
  display_shots(player->shots);
  cursor_char(player->shots, pos.i, pos.j, 0);
}

void		touched_(int a)
{
  if (a == 1)
    {
      attron(COLOR_PAIR(CRED) | A_BOLD);
      mvprintw(4, COLS / 2 - 8, "{Ennemy Hit !}");
      refresh();
    }
  if (a == 0)
    {
      attron(COLOR_PAIR(CGREEN) | A_BOLD);
      mvprintw(4, COLS / 2 - 8, "{Ennemy missed !}");
      refresh();
    }
}

void		display_host(int a)
{
  attron(COLOR_PAIR(CYELLOW) | A_BOLD);
  mvprintw(LINES / 2 - a, COLS / 2 - 10, "->");
  (a == 0) ? attron(COLOR_PAIR(CYELLOW) | A_BOLD) :
    attron(COLOR_PAIR(CWHITE) | A_BOLD);
  mvprintw(LINES / 2, COLS / 2 - 8, "[Hosting game]");
  (a == 1) ? attron(COLOR_PAIR(CYELLOW) | A_BOLD) :
    attron(COLOR_PAIR(CWHITE) | A_BOLD);
  mvprintw(LINES / 2 - 1, COLS / 2 - 8, "[Join a game]");
}
