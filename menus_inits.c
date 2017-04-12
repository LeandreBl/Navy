/*
** menus_inits.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 15:42:36 2017 Léandre Blanchard
** Last update Mon Feb 20 02:44:05 2017 Léandre Blanchard
*/

#include "navy.h"

void            init_screen_menu()
{
  initscr();
  clear();
  curs_set(0);
  start_color();
  keypad(stdscr, TRUE);
  init_color_pairs();
}
