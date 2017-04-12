/*
** my_strlowcase.c for my_strlowcase in /home/lblanchard/CPool_Day06
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Oct 10 13:31:40 2016 Leandre Blanchard
** Last update Mon Oct 10 14:34:47 2016 Leandre Blanchard
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] =! '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  str[i] = str[i] + 32;
	}
      i = i + 1;
    }
  return str;
}
