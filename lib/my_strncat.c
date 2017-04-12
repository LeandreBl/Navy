/*
** my_strncat.c for my_strncat in /home/lblanchard/CPool_Day07
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Oct 11 11:09:15 2016 Leandre Blanchard
** Last update Mon Jan 16 07:33:48 2017 Léandre Blanchard
*/

int	my_strlen(char *);

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && nb > 0)
    {
      dest[my_strlen(dest) + i] = src[i];
      i = i + 1;
      nb = nb - 1;
    }
  dest[my_strlen(dest) + 1] = '\0';
  return dest;
}
