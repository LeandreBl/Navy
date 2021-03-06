/*
** my_strncpy.c for my_strncpy in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Fri Oct  7 11:01:26 2016 Leandre Blanchard
** Last update Fri Oct  7 13:34:00 2016 Leandre Blanchard
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (n > 0 && *(src + i))
    {
      *(dest + i) = *(src + i);
      i = i + 1;
      n = n - 1;
    }
  if (n > 0)
    *(dest + i) = ('\0');
  return (dest);
}
