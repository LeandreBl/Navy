/*
** char_to_nchar.c for char_to_nchar in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 21:48:25 2016 Leandre Blanchard
** Last update Tue Nov  8 21:50:21 2016 Leandre Blanchard
*/

#include <stdlib.h>
#include <stdarg.h>

char	*my_strcpyn(char *, char *, int);
int	my_strlen(char *);
char	*my_strdup(char *);

char    *char_to_nchar(va_list va, int n)
{
  char  *str;
  char  *va_cpy;

  va_cpy = my_strdup(va_arg(va, char *));
  if (n > my_strlen(va_cpy))
    n = my_strlen(va_cpy);
  str = malloc(sizeof (char) * n + 1);
  my_strcpyn(str, va_cpy, n);
  return (str);
}
