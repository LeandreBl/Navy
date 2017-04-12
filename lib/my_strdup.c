/*
** my_strdup.c for my_strdup in /home/lblanchard/CPool_Day08
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Oct 12 09:15:56 2016 Leandre Blanchard
** Last update Sat Jan 21 18:48:51 2017 Léandre Blanchard
*/

#include <stdlib.h>

int	my_strlen(char *);
char	*my_strcpy(char *, char *);

char	*my_strdup(char *src)
{
  char	*dest;

  if (src == NULL)
    return (NULL);
  dest = malloc(sizeof(char) * (my_strlen(src) + 10));
  my_strcpy(dest, src);
  return (dest);
}
