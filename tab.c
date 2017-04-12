/*
** tab.c for navy in /home/leandre/System_unix/PSU_2016_navy/bonus
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Feb  2 17:47:06 2017 Léandre Blanchard
** Last update Thu Feb  2 18:11:30 2017 Léandre Blanchard
*/

#include "navy.h"

void		my_put_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    printf("%s\n", tab[i++]);
}

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
