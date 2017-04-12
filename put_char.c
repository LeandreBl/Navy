/*
** put_char.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 17:54:38 2017 Léandre Blanchard
** Last update Fri Feb  3 19:59:17 2017 Léandre Blanchard
*/

#include "navy.h"

void            dot_char(char **tab, int i, int j)
{
  j *= 2;
  attron(COLOR_PAIR(5) | A_BOLD);
  mvprintw(LINES / 2 - my_tablen(tab) / 2 + i,
	   COLS / 2 - my_strlen(tab[i]) + j, ".");
}

void		sharp_char(char **tab, int i, int j)
{
  j *= 2;
  attron(COLOR_PAIR(7) | A_BOLD);
  mvprintw(LINES / 2 - my_tablen(tab) / 2 + i,
	   COLS / 2 - my_strlen(tab[i]) + j, "#");
}

void		put_char_on(char **tab, int i, int j)
{
  if (tab[i][j] == '.')
    dot_char(tab, i, j);
  if (tab[i][j] == '#')
    sharp_char(tab, i, j);
}

void		cursor_char(char **tab, int i, int j, int game)
{
  int		k;

  k = (game == 0) ? i + 4 : i;
  if (tab[i][j] == '#')
    {
      j *= 2;
      attron(COLOR_PAIR(8) | A_BOLD);
      mvprintw(LINES / 2 - my_tablen(tab) / 2 + k,
	       COLS / 2 - my_strlen(tab[i]) + j, "#");
    }
  else if (tab[i][j] == '.')
    {
      j *= 2;
      attron(COLOR_PAIR(9) | A_BOLD);
      mvprintw(LINES / 2 - my_tablen(tab) / 2 + k,
	       COLS / 2 - my_strlen(tab[i]) + j, ".");
    }
  else
    o_or_x(tab, i, j, game);
  j /= 2;
  attron(COLOR_PAIR(5));
  mvprintw(LINES / 2 + 6 + k - i, COLS / 2 - 2,
	   "[%c%d]", j + 'A', i + 1);
}

void		o_or_x(char **tab, int i, int j, int game)
{
  int		k;

  k = (game == 0) ? i + 4 : i;
  if (tab[i][j] == 'o')
   {
     j *= 2;
     attron(COLOR_PAIR(11) | A_BOLD);
     mvprintw(LINES / 2 - my_tablen(tab) / 2 + k,
	      COLS / 2 - my_strlen(tab[i]) + j, "o");
   }
  else if (tab[i][j] == 'x')
    {
      j *= 2;
      attron(COLOR_PAIR(10) | A_BOLD);
      mvprintw(LINES / 2 - my_tablen(tab) / 2 + k,
	       COLS / 2 - my_strlen(tab[i]) + j, "x");
    }
}
