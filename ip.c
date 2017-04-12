/*
** ip.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Feb  4 18:21:30 2017 Léandre Blanchard
** Last update Sun Feb 19 15:00:54 2017 Léandre Blanchard
*/

#include "navy.h"

void			socket_init_host(t_player *player)
{
  socklen_t		clilen;
  struct sockaddr_in	cli_addr;
  struct sockaddr_in	serv_addr;

  player->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORTNO);
  bind(player->sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
  listen(player->sock_fd, 5);
  clilen = sizeof(cli_addr);
  player->new_fd = accept(player->sock_fd, (struct sockaddr *) &cli_addr,
			  &clilen);
  write(player->new_fd, "OK\0", 3);
}

int			socket_init_cli(t_player *player)
{
  struct sockaddr_in	serv_addr;
  struct hostent	*server;
  char			buffer[3];

  player->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  server = gethostbyname(player->ip);
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *) &serv_addr.sin_addr.s_addr,
	server->h_length);
  serv_addr.sin_port = htons(PORTNO);
  connect(player->sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
  player->new_fd = player->sock_fd;
  bzero(buffer, 3);
  read(player->sock_fd, buffer, 3);
  if (buffer[0] == 'O' && buffer[1] == 'K')
    return (0);
  sleep(TIME_OUT);
  clear();
  attron(COLOR_PAIR(CRED) | A_BOLD);
  mvprintw(LINES / 2, COLS / 2 - 11, "Connection Timed Out");
  refresh();
  sleep(3);
  return (1);
}

void			receive_shot(t_player *player, t_xy pos)
{
  char			buffer[3];
  static int		nb;

  attron(COLOR_PAIR(CBLUE) | A_BOLD);
  mvprintw(3, 3, "Ennemy Turn ...");
  refresh();
  read(player->new_fd, buffer, 3);
  rec_shot(player, buffer);
  if (boats_nb(player->map) != nb)
    nb = boats_nb(player->map);
  if (nb == 5 || nb == 3 || nb == 1)
    system("aplay -q sounds/mer.wav&");
  solo_display(player, pos);
  refresh();
}

void			send_shot(t_player *player, t_xy pos)
{
  char			buffer[3];

  if (player->shots[pos.i][pos.j] != '.'
      && boats_nb(player->map) != 0 && x_nb(player->shots) != 14)
    return;
  buffer[0] = pos.i;
  buffer[1] = pos.j;
  buffer[2] = 0;
  write(player->new_fd, buffer, 3);
  bzero(buffer, 3);
  read(player->new_fd, buffer, 3);
  if (buffer[0] == 'O' && buffer[1] == 'K')
    player->shots[pos.i][pos.j] = 'x';
  else
    player->shots[pos.i][pos.j] = 'o';
  solo_display(player, pos);
  receive_shot(player, pos);
}
