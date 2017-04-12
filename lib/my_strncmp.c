/*
** my_strncmp.c for my_strncmp in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Sat Jan 21 15:20:35 2017 Léandre Blanchard
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  if (s1[0] != '\0' && s2[0] != '\0')
    {
      i = 0;
      while ((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0' && i != n - 1)
	i++;
      return (s1[i] - s2[i]);
    }
  return (0);
}
