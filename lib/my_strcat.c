/*
** my_strcat.c for my_strcat in /home/lblanchard/CPool_Day07
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Oct 11 09:27:45 2016 Leandre Blanchard
** Last update Sat Jan 21 19:00:51 2017 Léandre Blanchard
*/

int	my_strlen(char *);

char	*my_strcat(char *dest, char *src)
{
  char	*ret;

  ret = dest;
  while (*dest)
    dest++;
  while (*dest++ = *src++);
  return (ret);
}
