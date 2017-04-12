/*
** nb_arg.c for nb_arg in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 21:15:26 2016 Leandre Blanchard
** Last update Tue Nov  8 21:41:00 2016 Leandre Blanchard
*/

#include <stdlib.h>

char	*my_strncpy(char *, const char *, int);
int	my_strlen(char *);
int	my_strlenconst(const char *);
char	*my_strdup(char *);
char	*int_to_char(int);
int	my_getnbr(char *);

int     nb_arg(const char *format, int i)
{
  char  *part;
  int   len;

  part = malloc(sizeof (char) * my_strlenconst(format) + 1);
  my_strncpy(part, format, i);
  len = my_strlen(my_strdup(int_to_char(my_getnbr(part)))) + 3;
  return (len);
}
