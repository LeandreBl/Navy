/*
** display_multi.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Feb  4 19:23:25 2017 Léandre Blanchard
** Last update Sun Feb 19 15:10:28 2017 Léandre Blanchard
*/

#include "navy.h"

void		display_host_wait(t_player *player)
{
  clear();
  attron(COLOR_PAIR(CGREEN) | A_BOLD);
  mvprintw(LINES / 2, COLS / 2 - 14, "Waiting for ennemy to connect...");
  refresh();
  socket_init_host(player);
  system("kill $(pgrep aplay)");
  in_game_sound();
  clear();
  refresh();
}

void		display_connection(t_player *player)
{
  clear();
  attron(COLOR_PAIR(CWHITE) | A_BOLD);
  mvprintw(LINES / 2 - 1, COLS / 2 - 9, "Enter host ip here :");
  mvprintw(LINES / 2, COLS / 2 - my_strlen(player->ip) / 2,
	   "[%s]", player->ip);
  refresh();
}

int		waiting_connection(t_player *player)
{
  attron(COLOR_PAIR(CWHITE) | A_BOLD);
  mvprintw(LINES / 2 - 1, COLS / 2 - 7 - my_strlen(player->ip) / 2,
	   "Ennemy ip -> {%s}", player->ip);
  attron(COLOR_PAIR(CGREEN) | A_BOLD);
  mvprintw(LINES / 2, COLS / 2 - 11, "Waiting for connection.  ");
  usleep(333333);
  refresh();
  mvprintw(LINES / 2, COLS / 2 - 11, "Waiting for connection.. ");
  usleep(333333);
  refresh();
  mvprintw(LINES / 2, COLS / 2 - 11, "Waiting for connection...");
  usleep(333333);
  refresh();
  return (socket_init_cli(player));
}

void		you_lose_multi(t_player *player)
{
  char		buffer[3];

  clear();
  system("kill $(pgrep aplay)");
  system("aplay -q sounds/lose.wav&");
  refresh();
  buffer[0] = 1;
  buffer[1] = 1;
  buffer[2] = 0;
  write(player->new_fd, buffer, 3);
  attron(COLOR_PAIR(CRED) | A_BOLD);
  mvprintw(LINES / 2, COLS / 2 - 6, "Ennemy won !");
  mvprintw(LINES / 2 - 1, COLS / 2 - 11,
	   "Ennemy ships left : %d", 14 - x_nb(player->shots));
  refresh();
  sleep(3);
}

void		you_win_multi(t_player *player)
{
  clear();
  system("kill $(pgrep aplay)");
  system("aplay -q sounds/victory.wav&");
  refresh();
  attron(COLOR_PAIR(CGREEN) | A_BOLD);
  mvprintw(LINES / 2, COLS / 2 - 5, "You won !");
  mvprintw(LINES / 2 - 1, COLS / 2 - 7,
	   "Ships left : %d", boats_nb(player->map));
  refresh();
  sleep(3);
}

