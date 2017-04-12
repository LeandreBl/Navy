/*
** my_find_prime_sup.c for my_find_prime_sup in /home/lblanchard/CPool_Day05
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Fri Oct  7 19:41:59 2016 Leandre Blanchard
** Last update Fri Oct  7 21:34:54 2016 Leandre Blanchard
*/

int	my_is_prime();

int	my_find_prime_sup(int nb)
{
  if (nb > 2 && nb % 2 == 0)
    {
      nb = nb + 1;
    }
  while (!my_is_prime(nb))
    {
      nb = nb + 2;
    }
  return (nb);
}
