/*
** menu_sounds.c for navy in /home/leandre/Games/Navy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Feb 22 21:16:40 2017 Léandre Blanchard
** Last update Thu Feb 23 15:49:51 2017 Léandre Blanchard
*/

#include "navy.h"

void		display_sounds(int perc)
{
  char		line[22];

  my_strcpy(line, "[---------------------]");
  line[23] = 0;
  attron(COLOR_PAIR(CBLUE) | A_BOLD);
  mvprintw(LINES / 2 - 1, COLS / 2 - 5, "Sound settings");
  mvprintw(LINES / 2, COLS / 2 - 16, "Change the Volume using < and > keys");
  attron(COLOR_PAIR(CYELLOW) | A_BOLD);
  mvprintw(LINES / 2 + 2, COLS / 2, "%d", perc);
  attron(COLOR_PAIR(CWHITE) | A_BOLD);
  mvprintw(LINES / 2 + 1, COLS / 2 - 11, "%s", line);
  attron(COLOR_PAIR(CYELLOW) | A_BOLD);
  mvprintw(LINES / 2 + 1, COLS / 2 - 10 + (perc / 5), "|");
}

int		my_strleni(int nb)
{
  int		i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}

char            *int_char(int nb)
  {
    char          *str;
    int           i;
    int           ret;

    ret = 0;
    if ((str = malloc(my_strleni(nb) + 1)) == NULL)
      return (NULL);
    bzero(str, my_strleni(nb) + 1);
    i = 0;
    if (nb < 0)
      {
	nb = nb * -1;
	ret = 1;
      }
    while (nb != 0)
      {
	str[i] = (nb % 10) + 48;
	nb = nb / 10;
	i++;
      }
    if (ret == 1)
      str[i] = '-';
    return (my_revstr(str));
}

void		menu_sounds()
{
  int		i;
  static int	perc = 60;
  char		*cmd;
  char		*add;

  if ((cmd = my_strdup("amixer set Master     ")) == NULL)
    return;
  system("amixer set Master unmute");
  system("amixer set Speaker unmute");
  system("amixer set Headphone unmute");
  i = 0;
  while (i != 'x' && i != 10)
    {
      clear();
      display_sounds(perc);
      refresh();
      i = getch();
      perc = (i == KEY_LEFT) ? perc - 5 : perc;
      perc = (i == KEY_RIGHT) ? perc + 5 : perc;
      perc = (perc > 100) ? 100 : perc;
      perc = (perc < 0) ? 0 : perc;
      cmd[18] = 0;
      add = int_char(perc);
      my_strcat(cmd, add);
      my_strcat(cmd, "%\0");
      free(add);
      system(cmd);
    }
  free(cmd);
}
