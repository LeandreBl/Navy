/*
** my_strcmp.c for my_strcmp in /home/lblanchard/CPool_Day06
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Thu Oct  6 11:19:22 2016 Leandre Blanchard
** Last update Tue Oct 11 19:05:54 2016 Leandre Blanchard
*/

int	my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}

