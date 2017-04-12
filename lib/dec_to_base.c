/*
** dec_to_base.c for dec_to_base in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 16:35:25 2016 Leandre Blanchard
** Last update Wed Nov  9 11:32:06 2016 Leandre Blanchard
*/

#include <stdlib.h>

int	my_strlen(char *);
void	my_putchar(int);

long long     dec_to_base(long long dec, long base)
{
  long long   result;
  long long   i;

  i = 1;
  result = 0;
  while (dec != 0)
    {
      result = result + (dec % base) * i;
      dec = dec / base;
      i = i * 10;
    }
  return (result);
}
