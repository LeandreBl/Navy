/*
** my_putstr.c for my_putstr in /home/lblanchard/CPool_Day04
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Mon Jan 16 07:32:49 2017 Léandre Blanchard
*/

#include <unistd.h>

int	my_strlen(char *);

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
