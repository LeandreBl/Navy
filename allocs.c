/*
** allocs.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 16:20:39 2017 Léandre Blanchard
** Last update Wed Feb  8 16:53:51 2017 Léandre Blanchard
*/

#include "navy.h"

char		*my_calloc(int size)
{
  int		i;
  char		*str;

  if ((str = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  while (i != size)
    str[i++] = 0;
  str[size - 1] = 0;
  return (str);
}

char		**my_tab_alloc()
{
  char		**tab;

  if ((tab = malloc(sizeof(char **) * 9)) == NULL)
    return (NULL);
  return (tab);
}
