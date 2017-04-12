/*
** realloc.c for mnishell in /home/leandre/System_unix/PSU_2016_minishell1
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat Jan 21 17:29:08 2017 Léandre Blanchard
** Last update Sat Jan 21 18:06:36 2017 Léandre Blanchard
*/

#include <stdlib.h>

int		my_strlen(char *);

char            *my_realloc(char *str, int size)
{
  char          *dest;
  int           i;

  i = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(str) + size))) == NULL)
    return (NULL);
  while (i != size)
    {
      dest[i] = 0;
      i = i + 1;
    }
  i = 0;
  while (str[i] != '\0')
    {
      dest[i] = str[i];
      i = i + 1;
    }
  return (dest);
}
