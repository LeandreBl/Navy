/*
** navy.h for navy in /home/leandre/System_unix/PSU_2016_navy
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Feb  1 12:28:50 2017 Léandre Blanchard
** Last update Wed Feb 22 21:24:53 2017 Léandre Blanchard
*/

#ifndef NAVY_H_
# define NAVY_H_

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <ncurses.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <time.h>
# include <netdb.h>
# include <math.h>

# include "my.h"
# include "colors.h"

# define CRED     3
# define CMAGENTA 1
# define CGREEN   2
# define CYELLOW  4
# define CWHITE   5
# define CCYAN    6
# define CBLUE    7
# define TIME_OUT 10
# define PORTNO   5001
# define MAX_H_   50

typedef struct	s_xy
{
  int		i;
  int		j;
}		t_xy;

typedef struct	s_vars
{
  int		i;
  int		j;
  int		k;
}		t_vars;

typedef struct	s_player
{
  char		**map;
  char		**shots;
  char		*ip;
  int		sock_fd;
  int		new_fd;
}		t_player;

int		multiplayer;

void		menu_sounds();

void		fire_work();

void		display_holes();

void		solo_win();

void		solo_lose();

void		in_game_sound();

void		you_lose_multi(t_player *);

void		you_win_multi(t_player *);

int		rec_shot(t_player *, char *);

int		win_lose(t_player *);

void		catch_quit(int);

int		x_nb(char **);

void		init_exchange(t_player *);

void		receive_shot(t_player *, t_xy);

void		send_shot(t_player *, t_xy);

void		socket_init_host(t_player *);

int		socket_init_cli(t_player *);

void		display_host_wait(t_player *);

int		main(void);

void		display_connection(t_player *);

int		waiting_connection(t_player *);

char		*my_calloc(int);

void		solo_display(t_player *, t_xy);

void		o_or_x(char **, int, int, int);

void		display_host(int);

int		move_arrow_2(int, int);

t_xy		init_xy(int, int);

int		fill_bot(t_player *);

void		display_shots(char **);

void		turn();

void		touched_(int);

void		display_my(char **);

int		multi(t_player *);

void		free_player(t_player *, char **);

void		borders(int);

int		solo(t_player *);

void		insert_delete(t_xy, char **, int);

void		cursor_char(char **, int, int, int);

t_xy		move_pos_arrow(int, t_xy);

void		display_cube();

char		**map_gen_display(char **);

void		put_char_on(char **, int, int);

int		my_tablen(char **);

int		boats_nb(char **);

void		display_map(char **);

void		display_navy();

void		display_rules();

char		**my_tab_alloc();

char		**map_gen();

void		free_tab(char **);

void		my_put_tab(char **);

void		init_screen_menu();

char		**launch_menu(int);

void		init_color_pairs();

int		move_arrow(int, int);

void		display_menu_boxes();

char		**menu_map();

int		fill_player(t_player *);

int		game_menu(t_player *);

#endif /* !NAVY_H_ */
