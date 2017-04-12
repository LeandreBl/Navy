/*
** solo.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 22:04:09 2017 Léandre Blanchard
** Last update Thu Feb 23 11:24:33 2017 Léandre Blanchard
*/

#include "navy.h"

int		end_screen(t_player *player, t_player *bot)
{
  int		i;

  i = 0;
  system("kill $(pgrep aplay)");
  clear();
  while (i != 'x' && i != 'X' && i != 'r' && i != 'R')
    {
      clear();
      if (boats_nb(bot->map) == 0)
	solo_win();
      if (boats_nb(player->map) == 0 && boats_nb(bot->map) != 0)
	solo_lose();
      attron(COLOR_PAIR(CBLUE));
      mvprintw(LINES / 2 - 1, COLS / 2 - 16,
	       "Press [x] to quit or [r] to restart");
      i = getch();
    }
  free_player(player, player->map);
  free_player(bot, bot->map);
  if (i == 'r' || i == 'R')
    {
      system("kill $(pgrep aplay)");
      main();
    }
  return (1);
}

void		fire_bot(t_player *player, t_xy att)
{
  if (player->map[att.i][att.j] != '.')
    {
      touched_(1);
      system("aplay -q sounds/hit.wav&");
      player->map[att.i][att.j] = 'x';
    }
  else
    {
      system("aplay -q sounds/plouf.wav&");
      player->map[att.i][att.j] = 'o';
      touched_(0);
    }
}

void		ia_bot(t_player *bot, t_player *player, t_xy pos)
{
  t_xy		att;

  if (player->shots[pos.i][pos.j] != '.')
    return;
  if (bot->map[pos.i][pos.j] == '#')
    {
      system("aplay -q sounds/hit.wav&");
      player->shots[pos.i][pos.j] = 'x';
      bot->map[pos.i][pos.j] = 'x';
    }
  else
    player->shots[pos.i][pos.j] = 'o';
  display_shots(player->shots);
  refresh();
  turn();
  att = init_xy(rand() % 8, rand() % 8);
  while (bot->shots[att.i][att.j] == 'x' && boats_nb(bot->map) > 5)
    att = init_xy(rand() % 8, rand() % 8);
  while (player->map[att.i][att.j] != '#' && boats_nb(bot->map) <= 5)
    att = init_xy(rand() % 8, rand() % 8);
  bot->shots[att.i][att.j] = 'x';
  fire_bot(player, att);
  usleep(300000);
}

int		solo(t_player *player)
{
  t_player	*bot;
  int		i;
  t_xy		pos;

  if ((bot = malloc(sizeof(t_player))) == NULL)
    return (84);
  if (fill_bot(bot) == 84)
    return (84);
  i = 0;
  pos = init_xy(0, 0);
  in_game_sound();
  while (i != 'x' && i != 'X')
    {
      solo_display(player, pos);
      i = getch();
      if (i == 10)
	ia_bot(bot, player, pos);
      if (boats_nb(bot->map) == 0 || boats_nb(player->map) == 0)
	return (end_screen(player, bot));
      pos = move_pos_arrow(i, pos);
      refresh();
    }
  free_player(bot, bot->map);
  return (1);
}
