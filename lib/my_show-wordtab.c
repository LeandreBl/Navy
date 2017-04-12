/*
** my_show_wordtab.c for my_show_wordtab in /home/lblanchard/CPool_Day08/task03
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Wed Oct 12 20:19:53 2016 Leandre Blanchard
** Last update Tue Nov  8 10:03:16 2016 Leandre Blanchard
*/

void	my_putstr(char *);
void	my_putchar(char );

int	my_show_wordtab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[i] != '\0')
    {
      j = 0;
      my_putstr(" [");
      while (tab[i][j] != '\0')
	{
	  my_putchar(tab[i][j]);
	  j = j + 1;
	}
      my_putstr("] ");
      i = i + 1;
    }
  return (0);
}
