/*
** multi.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Feb  3 16:44:45 2017 Léandre Blanchard
** Last update Thu Feb 23 15:41:14 2017 Léandre Blanchard
*/

#include "navy.h"

int		host_game(t_player *player)
{
  int		i;
  t_xy		pos;

  i = 0;
  pos = init_xy(0, 0);
  display_host_wait(player);
  solo_display(player, pos);
  receive_shot(player, pos);
  while (i != 'x' && i != 'X')
    {
      solo_display(player, pos);
      i = getch();
      pos = move_pos_arrow(i, pos);
      if (i == 10)
	send_shot(player, pos);
      if (i == 197)
	write(player->new_fd, "sex", 3);
      if (win_lose(player) == 0)
	break;
      refresh();
    }
  endwin();
  close(player->new_fd);
  close(player->sock_fd);
  return (main());
}

int		join(t_player *player)
{
  int		i;
  t_xy		pos;

  i = 0;
  pos = init_xy(0, 0);
  if (waiting_connection(player) == 1)
    return (multi(player));
  in_game_sound();
  while (i != 'x' && i != 'X')
    {
      solo_display(player, pos);
      i = getch();
      pos = move_pos_arrow(i, pos);
      if (i == 10)
	send_shot(player, pos);
      if (i == 197)
	write(player->new_fd, "sex", 3);
      if (win_lose(player) == 0)
	break;
    }
  endwin();
  system("kill $(pgrep aplay)");
  close(player->sock_fd);
  close(player->new_fd);
  return (main());
}

int		join_game(t_player *player)
{
  int		i;
  int		k;

  k = 0;
  system("kill $(pgrep aplay)");
  system("aplay -q sounds/try_co.wav&");
  clear();
  while (1)
    {
      display_connection(player);
      i = getch();
      if (i == 'x' || i == 'X')
	{
	  system("kill $(pgrep aplay)");
	  return (multi(player));
	}
      if (i == KEY_BACKSPACE)
	player->ip[--k] = 0;
      k = (k < 0) ? 0 : k;
      if ((k < 16 && (i >= '0' && i <= '9')) || i == '.')
	  player->ip[k++] = i;
      if (i == 10)
	return (join(player));
    }
  return (1);
}

int		network(t_player *player, int host)
{
  system("aplay -q sounds/menu.wav&");
  if ((player->ip = my_calloc(17)) == NULL)
    return (84);
  if (host == 1)
    return (join_game(player));
  if (host == 0)
    return (host_game(player));
  return (84);
}

int		multi(t_player *player)
{
  int		i;
  int		a;

  a = 1;
  system("kill $(pgrep aplay)");
  system("aplay -q sounds/waiting_co.wav&");
  while (1)
    {
      clear();
      display_host(a);
      i = getch();
      a = move_arrow_2(a, i);
      if (i == 'x' || i == 'X')
	{
	  system("kill $(pgrep aplay)");
	  return (main());
	}
      if (i == 10)
	return (network(player, a));
      refresh();
    }
  return (0);
}
