/*
** quick_display.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 14:07:41 2017 Léandre Blanchard
** Last update Wed Feb 22 21:15:36 2017 Léandre Blanchard
*/

#include "navy.h"

void		display_menu_boxes(int a)
{
  attron(COLOR_PAIR(5) | A_BOLD);
  mvprintw(LINES / 2 - 5, COLS / 2 - 19,
	   "/------------------------------------\\");
  mvprintw(LINES / 2 + 2, COLS / 2 - 19,
	   "\\------------------------------------/");
  (a == 0) ? attron(COLOR_PAIR(4) | A_BOLD) : attron(COLOR_PAIR(5) | A_BOLD);
  mvprintw(LINES / 2 - 3, COLS / 2 - 6, "[Solo]");
  (a == 1) ? attron(COLOR_PAIR(4) | A_BOLD) : attron(COLOR_PAIR(5) | A_BOLD);
  mvprintw(LINES / 2 - 2, COLS / 2 - 6, "[Multiplayer]");
  (a == 2) ? attron(COLOR_PAIR(4) | A_BOLD) : attron(COLOR_PAIR(5) | A_BOLD);
  mvprintw(LINES / 2 - 1, COLS / 2 - 6, "[Rules]");
  (a == 3) ? attron(COLOR_PAIR(4) | A_BOLD) : attron(COLOR_PAIR(5) | A_BOLD);
  mvprintw(LINES / 2, COLS / 2 - 6, "[Sounds]");
  attron(COLOR_PAIR(2) | A_BOLD);
  mvprintw(LINES / 2 + 4, COLS / 2 - 20,
	   "Press [ESCAPE] x 2 to quit or press [x]");
  attron(COLOR_PAIR(4) | A_BOLD);
  mvprintw(LINES / 2 + a - 3, COLS / 2 - 9, "->");
}

void		display_rules()
{
  clear();
  display_navy();
  attron(COLOR_PAIR(5) | A_BOLD);
  mvprintw(LINES / 2 - 4,
	   COLS / 2 - 18, "/----------------------------------\\");
  mvprintw(LINES / 2 + 2,
	   COLS / 2 - 18, "\\----------------------------------/");
  attron(COLOR_PAIR(2) | A_BOLD);
  mvprintw(LINES / 2 - 3,
	   COLS / 2 - 18, "|  The goal of the game is         |");
  mvprintw(LINES / 2 - 2,
	   COLS / 2 - 18, "|  to sunk every ships of the      |");
  mvprintw(LINES / 2 - 1,
	   COLS / 2 - 18, "|  ennemy player using shots       |");
  mvprintw(LINES / 2 + 0,
	   COLS / 2 - 18, "|  each turn, and to aim           |");
  mvprintw(LINES / 2 + 1,
	   COLS / 2 - 18, "|  precisely in order to hit them  | ");
  mvprintw(LINES / 2 + 4, COLS / 2 - 14, "[Press any key to continue]");
  refresh();
  getch();
}

void		display_navy()
{
  attron(COLOR_PAIR(7) | A_BOLD);
  mvprintw(LINES / 2 - 11, COLS / 2 - 18,
	   "_     _      ___    _         _  _    _");
  mvprintw(LINES / 2 - 10, COLS / 2 - 18,
	   "|\\    |     /   \\   \\         /  \\    /");
  mvprintw(LINES / 2 - 9, COLS / 2 - 18,
	   "| \\   |    /     \\   \\       /    \\  / ");
  mvprintw(LINES / 2 - 8, COLS / 2 - 18,
	   "|  \\  |   /_______\\   \\     /      \\/  ");
  mvprintw(LINES / 2 - 7, COLS / 2 - 18,
	   "|   \\ |  /         \\   \\   /       /   ");
  mvprintw(LINES / 2 - 6, COLS / 2 - 18,
	   "|    \\| /           \\   \\_/      _/    ");
}

void		display_cube(int a)
{
  attron(COLOR_PAIR(3) | A_BOLD);
  mvprintw(LINES / 2 - a - 5, COLS / 2 - 10, "/-----------------\\");
  mvprintw(LINES / 2 - a + 4, COLS / 2 - 10, "\\-----------------/");
  if (a != 0)
    return;
  attron(COLOR_PAIR(4) | A_BOLD);
  mvprintw(LINES / 2 - 11, COLS / 2 - 16,
	   "Press SPACE to add a ship_chunk");
  mvprintw(LINES / 2 - 10, COLS / 2 - 15,
	   "and [d] to erase a ship_chunk");
}

void		borders(int a)
{
  attron(COLOR_PAIR(CWHITE) | A_BOLD);
  mvprintw(LINES / 2 - a - 5, COLS / 2 - 8, "A B C D E F G H");
  mvprintw(LINES / 2 - a + 4, COLS / 2 - 8, "A B C D E F G H");
  mvprintw(LINES / 2 - a - 4, COLS / 2 - 10, "1");
  mvprintw(LINES / 2 - a - 3, COLS / 2 - 10, "2");
  mvprintw(LINES / 2 - a - 2, COLS / 2 - 10, "3");
  mvprintw(LINES / 2 - a - 1, COLS / 2 - 10, "4");
  mvprintw(LINES / 2 - a, COLS / 2 - 10, "5");
  mvprintw(LINES / 2 - a + 1, COLS / 2 - 10, "6");
  mvprintw(LINES / 2 - a + 2, COLS / 2 - 10, "7");
  mvprintw(LINES / 2 - a + 3, COLS / 2 - 10, "8");
  mvprintw(LINES / 2 - a - 4, COLS / 2 + 8, "1");
  mvprintw(LINES / 2 - a - 3, COLS / 2 + 8, "2");
  mvprintw(LINES / 2 - a - 2, COLS / 2 + 8, "3");
  mvprintw(LINES / 2 - a - 1, COLS / 2 + 8, "4");
  mvprintw(LINES / 2 - a, COLS / 2 + 8, "5");
  mvprintw(LINES / 2 - a + 1, COLS / 2 + 8, "6");
  mvprintw(LINES / 2 - a + 2, COLS / 2 + 8, "7");
  mvprintw(LINES / 2 - a + 3, COLS / 2 + 8, "8");
}
