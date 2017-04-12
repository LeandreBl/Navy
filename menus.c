/*
** menus.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 00:28:39 2017 Léandre Blanchard
** Last update Wed Feb 22 21:45:11 2017 Léandre Blanchard
*/

#include "navy.h"

char		**menu_map()
{
  int		a;
  int		i;

  system("aplay -q sounds/menu.wav&");
  system("aplay -q sounds/main_menu.wav&");
  init_screen_menu();
  a = 0;
  while (1)
    {
      clear();
      display_holes();
      display_menu_boxes(a);
      i = getch();
      if (i == 'x' || i == 'X' || i == 27)
	return (NULL);
      multiplayer = (a == 0) ? 0 : 1;
      if (i == 10 && (a == 0 || a == 1))
	return (map_gen());
      if (i == 10 && a == 2)
	display_rules();
      if (i == 10 && a == 3)
	menu_sounds();
      a = move_arrow(a, i);
      attron(COLOR_PAIR(3));
      refresh();
    }
  return (NULL);
}

char		**map_gen()
{
  char		**map;
  int		i;

  i = 0;
  system("aplay -q sounds/in.wav&");
  if ((map = my_tab_alloc()) == NULL)
    return (NULL);
  while (i != 8)
    map[i++] = my_strdup("........\0");
  map[8] = NULL;
  return (map_gen_display(map));
}

char		**map_gen_display(char **map)
{
  t_xy		pos;
  int		i;

  pos.i = 0;
  pos.j = 0;
  clear();
  while (1)
    {
      display_cube(0);
      display_map(map);
      cursor_char(map, pos.i, pos.j, 1);
      refresh();
      i = getch();
      clear();
      if (i == 'x' || i == 'X')
	{
	  free_tab(map);
	  map = menu_map();
	  return (map);
	}
      if (i == 10 && boats_nb(map) == 14)
	return (map);
      pos = move_pos_arrow(i, pos);
      insert_delete(pos, map, i);
    }
}
