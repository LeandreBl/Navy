/*
** pointeur.c for pointeru in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Nov  9 19:06:51 2016 Leandre Blanchard
** Last update Wed Nov 16 19:44:22 2016 Leandre Blanchard
*/

void	my_putstr(char *);
void	my_putnbr_base(long long, char *);
void	my_put_pointer(long long);

void	pointeur(void *i)
{
  my_putstr("0x");
  my_put_pointer((unsigned long long)i);
}
