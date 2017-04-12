/*
** scanf.c for scanf in /home/leandre/Prog_elem/my_scanf
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Jan 17 11:18:27 2017 Léandre Blanchard
** Last update Tue Jan 17 11:25:05 2017 Léandre Blanchard
*/

#include "scanf.h"

int		my_printf(const char *, ...);

char            *my_calloc(const int len)
{
  char          *ptr;
  int           i;

  i = 0;
  ptr = malloc(len);
  while (i != len)
    ptr[i++] = 0;
  return (ptr);
}

char            *my_scanf(const char *str)
{
  char          *buffer;

  buffer = my_calloc(sizeof(char) * 501);
  my_printf(str);
  read(0, buffer, 500);
  return (buffer);
}
