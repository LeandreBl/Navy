/*
** float_to_char.c for float_to_char in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Nov  9 12:26:31 2016 Leandre Blanchard
** Last update Wed Nov  9 15:02:51 2016 Leandre Blanchard
*/

void	my_put_nbr(long long);
void	my_putchar(int);

void	my_put_float(double nbr)
{
  int	integer;
  int	floating;

  integer = nbr / 1.0;
  my_put_nbr(integer);
  nbr = integer - nbr;
  my_putchar('.');
  floating = nbr * 1000000;
  while (floating % 10 == 0)
    floating = floating / 10;
  floating = floating * (-1);
  if (floating % 10 == 9)
    floating = floating + 1;
  while (floating % 10 == 0)
    floating = floating / 10;
  my_put_nbr(floating);
}
