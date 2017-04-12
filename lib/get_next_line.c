/*
** get_next_line.c for get_next_line in /home/leandre/Prog_elem/CPE_2016_getnextline
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jan  2 17:57:54 2017 Léandre Blanchard
** Last update Sat Jan 21 17:39:09 2017 Léandre Blanchard
*/

#include "get_next_line.h"

char		*my_realloa(char *str, int size)
{
  char		*dest;
  int		i;

  i = 0;
  if ((dest = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  while (i != size)
    {
      dest[i] = 0;
      i = i + 1;
    }
  i = 0;
  while (str[i] != '\0')
    {
      dest[i] = str[i];
      i = i + 1;
    }
  free(str);
  return (dest);
}

char		*get_next_line(const int fd)
{
  static int	line;
  static char	*file;
  char		rd_buf[READ_SIZE + 1];
  int		size;
  int		i;

  size = READ_SIZE + 1;
  if (line == 0)
    if ((file = malloc(size)) == NULL)
      return (NULL);
  while ((i = read(fd, rd_buf, READ_SIZE)) > 0 && line == 0)
    {
      file = my_realloa(file, size);
      rd_buf[i] = 0;
      file = my_strcat(file, rd_buf);
      size += READ_SIZE;
    }
  if (line_sender(file, line) != NULL && line != (-1))
    return (line_sender(file, line++));
  else
    {
      line = (-1);
      return (NULL);
    }
}

char		*line_sender(char *buffer, int line)
{
  t_vars	v;
  char		**tab;

  v.i = 0;
  v.k = 0;
  if ((tab = malloc(sizeof(char *) * my_strlen(buffer))) == NULL)
    return (NULL);
  while (buffer[v.i] != '\0')
    {
      v.j = 0;
      if ((tab[v.k] = malloc(my_strlen(buffer))) == NULL)
	return (NULL);
      while (buffer[v.i] != '\n' && buffer[v.i] != '\0')
	{
	  if (buffer[v.i] > 31 && buffer[v.i] < 127)
	    tab[v.k][v.j++] = buffer[v.i];
	  v.i = v.i + 1;
	}
      v.k = v.k + 1;
      if (buffer[v.i] != '\0')
	v.i++;
    }
  tab[v.k] = NULL;
  return (tab[line]);
}
