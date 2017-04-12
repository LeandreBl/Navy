/*
** my_isneg.c for my_isneg in /home/lblanchard/CPool_Day03
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Oct  5 10:53:39 2016 Leandre Blanchard
** Last update Mon Feb 20 17:05:34 2017 Léandre Blanchard
*/

void	my_putchar(char);

int	my_isneg(int n)
{
  if (n >= 0)
    my_putchar('P');
  else
    my_putchar('N');
  return (0);
}
