/*
** my_putnbr_base.c for my_putnbr_base in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Nov  9 11:32:20 2016 Leandre Blanchard
** Last update Mon Feb 20 17:13:23 2017 Léandre Blanchard
*/

#include <stdlib.h>

int     my_strlen(char *);
void    my_putchar(int);
char	*my_revstr(char *);
void	my_putstr(char *);
char	*my_strdup(char *);

int     part_of_base(char c, char *base)
{
  long	i;

  i = 0;
  while (base[i] != 0)
    {
      if (c == base[i])
	return (0);
      i = i + 1;
    }
  return (84);
}

void	my_put_pointer(long long nbr)
{
  char	*base;
  char	*result;
  unsigned long long	i;
  unsigned long long	j;

  j = 0;
  i = nbr;
  result = malloc(sizeof (char) * 100);
  base = my_strdup("0123456789abcedf");
  while (i)
    {
      result[j] = base[i % 16];
      i = i / 16;
      j = j + 1;
    }
  my_putstr(my_revstr(result));
}

void    my_putnbr_base(long long nbr, char *base)
{
  unsigned long long	basex;
  unsigned long long     i;
  char			*result;
  unsigned long long     j;

  j = 0;
  i = nbr;
  basex = my_strlen(base);
  result = malloc(sizeof (char) * 100);
  while (i)
    {
      result[j] = base[i % basex];
      i = i / basex;
      j = j + 1;
    }
  while (nbr)
    {
      if (part_of_base(result[nbr], base) == 0)
	my_putchar(result[nbr]);
      nbr = nbr - 1;
    }
  if (part_of_base(result[nbr], base) == 0)
    my_putchar(result[nbr]);
}

void    my_nputnbr_base(long long nbr, char *base, int n)
{
  long long     basex;
  long long     i;
  char          *result;
  long long     j;

  j = 0;
  i = nbr;
  basex = my_strlen(base);
  result = malloc(sizeof (char) * 100);
  while (i)
    {
      result[j++] = base[i % basex];
      i = i / basex;
    }
  while (nbr)
    {
      if (part_of_base(result[nbr], base) == 0 && n > 1)
	{
	  my_putchar(result[nbr]);
	  n = n - 1;
	}
      nbr = nbr - 1;
    }
  if (part_of_base(result[nbr], base) == 0)
    my_putchar(result[nbr]);
}
