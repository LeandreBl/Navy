/*
** sounds.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sun Feb 19 14:03:43 2017 Léandre Blanchard
** Last update Wed Feb 22 01:02:24 2017 Léandre Blanchard
*/

#include "navy.h"

void		in_game_sound()
{
  char		*sound;

  if ((sound = my_strdup("aplay -q sounds/game_0.wav&")) == NULL)
    return;
  sound[21] = 48 + rand() % 9;
  system(sound);
  free(sound);
}

void            locker()
{
  t_xy          xy;
  int           i;

  i = 0;
  xy.i = rand() % COLS;
  xy.j = rand() % LINES;
  attron(COLOR_PAIR(CYELLOW));
  while (i != LINES)
    mvprintw(i++, xy.i, "|");
  i = 0;
  while (i != COLS)
    mvprintw(xy.j, i++, "-");
  if (rand() % 2 == 0)
    {
      attron(COLOR_PAIR(CRED) | A_BOLD);
      mvprintw(xy.j, xy.i, "x");
    }
  else
    {
      attron(COLOR_PAIR(CBLUE) | A_BOLD);
      mvprintw(xy.j, xy.i, "o");
    }
}

void		display_holes()
{
  int		i;
  int		x;
  int		max;

  max = COLS / 6;
  i = 0;
  while (i < max)
    {
      x = rand() % 2;
      if (x % 2 == 0)
	{
	  attron(COLOR_PAIR(CBLUE) | A_BOLD);
	  mvprintw(rand() % LINES, rand() % COLS, "o");
	}
      else
	{
	  attron(COLOR_PAIR(CRED) | A_BOLD);
	  mvprintw(rand() % LINES, rand() % COLS, "x");
	}
      i++;
    }
  locker();
}

void		solo_win()
{
  attron(COLOR_PAIR(CGREEN));
  system("aplay -q sounds/victory.wav&");
  mvprintw(LINES / 2, COLS / 2 - 9, "You Win, well played!");
}

void		solo_lose()
{
  attron(COLOR_PAIR(CRED));
  system("aplay -q sounds/lose.wav&");
  mvprintw(LINES / 2, COLS / 2 - 7, "You Lose NOOOOOOB !");
}
