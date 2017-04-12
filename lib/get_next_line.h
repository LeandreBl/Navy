/*
** get_next_line.h for get_next_line in /home/leandre/Prog_elem/CPE_2016_getnextline
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Mon Jan  2 17:53:11 2017 Léandre Blanchard
** Last update Thu Jan 12 15:30:48 2017 Léandre Blanchard
*/

#ifndef NEXT_LINE
# ifndef READ_SIZE
#  define READ_SIZE (66)
# endif /* !READ_SIZE */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
typedef struct	s_vars
{
  int		i;
  int		j;
  int		k;
}		t_vars;

char		*get_next_line(const int);
char		*my_realloc(char *, int);
char		*my_strcat(char *, char *);
int		my_strlen(char *);
char		*line_sender(char *, int);
#endif /* !NEXT_LINE */
