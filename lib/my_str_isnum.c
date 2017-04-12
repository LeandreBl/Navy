/*
** my_str_isnum.c for my_str_isnum in /home/lblanchard/CPool_Day06
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Oct 10 15:07:36 2016 Leandre Blanchard
** Last update Mon Feb 20 17:14:43 2017 Léandre Blanchard
*/

int	my_str_isnum(char *str, char c)
{
  int	i;

  i = 0;
  if (str[0] == c);
    i = 1;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  i = i + 1;
	}
      else
	return (1);
    }
  return (0);
}
