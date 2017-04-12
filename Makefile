##
## Makefile for navy in /home/leandre/PSU_2016_navy
## 
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
## 
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Wed Feb 22 22:07:15 2017 Léandre Blanchard
##

NAME	= navy

CC	= gcc

LIB	= -L./lib -lmy -lncurses -lm

SRCS	= main.c \
	  menus.c \
	  free.c \
	  fill_player.c \
	  colors.c \
	  moves.c \
	  quick_display.c \
	  quick_display_2.c \
	  menus_inits.c \
	  allocs.c \
	  tab.c \
	  put_char.c \
	  display.c \
	  test.c \
	  solo.c \
	  multi.c \
	  xy.c \
	  ip.c \
	  display_multi.c \
	  sounds.c \
	  fire_work.c \
	  menu_sounds.c

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

CFLAGS	+= -W -Wall -Werror -Wextra -I ./include -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
