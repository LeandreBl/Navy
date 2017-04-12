/*
** colors.c for nacy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 14:12:02 2017 Léandre Blanchard
** Last update Mon Feb 20 03:04:02 2017 Léandre Blanchard
*/

#include "navy.h"

void		init_color_pairs()
{
  init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_BLUE, COLOR_BLACK);
  init_pair(8, COLOR_CYAN, COLOR_MAGENTA);
  init_pair(9, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(10, COLOR_RED, COLOR_MAGENTA);
  init_pair(11, COLOR_CYAN, COLOR_MAGENTA);
}
