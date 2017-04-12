/*
** my_strlenconst.c for my_strlen in /home/lblanchard/PSU_2016_my_printf
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Nov  8 21:14:46 2016 Leandre Blanchard
** Last update Tue Nov  8 21:14:54 2016 Leandre Blanchard
*/

int     my_strlenconst(const char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
