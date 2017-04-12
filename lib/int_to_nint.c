/*
** int_to_nint.c for int_to_nint in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 21:51:12 2016 Leandre Blanchard
** Last update Mon Feb 20 17:05:03 2017 Léandre Blanchard
*/

char	*int_to_char(int);
int	my_strlen(char *);
void	my_putchar(int);

int	returnint(int n, int nb, int num)
{
  n = my_strlen(int_to_char(nb)) - n;
  num = nb;
  if (n == 0)
    return (0);
  while (n != 0)
    {
      num = num / 10;
      n = n - 1;
    }
  if (n == my_strlen(int_to_char(nb)))
    return (nb);
  return (num);
}

int	int_to_nint(int nb, int n)
{
  int	num;
  int	zeros;

  zeros = n;
  if (zeros > my_strlen(int_to_char(nb)))
    {
      zeros = zeros - my_strlen(int_to_char(nb));
      while (zeros > 0)
	{
	  my_putchar('0');
	  zeros = zeros - 1;
	}
      return (nb);
    }
  n = my_strlen(int_to_char(nb)) - n;
  num = nb;
  while (n != 0)
    {
      num = num / 10;
      n = n - 1;
    }
  if (n == my_strlen(int_to_char(nb)))
    return (nb);
  return (returnint(n, nb, num));
}
