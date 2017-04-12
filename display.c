/*
** display.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 20:54:56 2017 Léandre Blanchard
** Last update Wed Feb  8 17:05:10 2017 Léandre Blanchard
*/

#include "navy.h"

void            display_map(char **map)
{
  t_xy          xy;

  xy.i = 0;
  while (map[xy.i] != NULL)
    {
      xy.j = 0;
      while (map[xy.i][xy.j] != 0)
	put_char_on(map, xy.i, xy.j++);
      curs_set(0);
      xy.i++;
    }
  borders(0);
}

void		display_line_space(char *line, int x)
{
  int		i;

  i = 0;
  while (line[i] != 0)
    {
      (line[i] == '.') ? attron(COLOR_PAIR(CWHITE) | A_BOLD) : 0;
      (line[i] == '#') ? attron(COLOR_PAIR(CBLUE) | A_BOLD) : 0;
      (line[i] == 'x') ? attron(COLOR_PAIR(CRED) | A_BOLD) : 0;
      (line[i] == 'o') ? attron(COLOR_PAIR(CCYAN) | A_BOLD) : 0;
      mvprintw(LINES / 2 - x,
	       COLS / 2 - my_strlen(line) + 2 * i, "%c", line[i]);
      i++;
    }
}

void		display_my(char **map)
{
  int		i;
  int		x;

  x = 15;
  i = 0;
  while (map[i] != NULL)
    display_line_space(map[i++], x--);
  attron(COLOR_PAIR(CYELLOW) | A_BOLD);
  mvprintw(LINES / 2 - 15, COLS / 2 - 40, "Your ships, [x] -> touched,");
  mvprintw(LINES / 2 - 14, COLS / 2 - 35, "and [#] -> ship alive");
  display_cube(11);
  borders(11);
  refresh();
}

void		display_shots(char **map)
{
  int		i;
  int		x;

  x = 0;
  i = 0;
  while (map[i] != NULL)
    display_line_space(map[i++], x--);
  attron(COLOR_PAIR(CYELLOW) | A_BOLD);
  mvprintw(LINES / 2, COLS / 2 - 40, "Your shots, [x] -> touched,");
  mvprintw(LINES / 2 + 1, COLS / 2 - 35, "and [o] -> missed");
  display_cube(-4);
  borders(-4);
  refresh();
}
