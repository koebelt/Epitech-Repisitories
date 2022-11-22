##
## EPITECH PROJECT, 2020
## B-MUL-100-STG-1-1-myhunter-thomas.koebel
## File description:
## Makefile
##

SRC 	=	audio.c	\
			bottle.c	\
			buttons.c	\
			choose.c	\
			crosshair.c	\
			disp_bottles1.c	\
			disp_bottles2.c	\
			game.c	\
			health.c	\
			hunter.c	\
			init_bottles1.c	\
			init_bottles2.c	\
			main.c	\
			menu.c	\
			init_menu.c	\
			menu_events.c	\
			my_getnbr.c	\
			my_int_to_str.c	\
			my_putchar.c	\
			my_putstr.c	\
			my_strcat.c	\
			particles.c	\
			save.c	\
			init_choose.c	\
			choose_index.c	\
			choose_mouse_click.c	\
			init_game.c	\
			disp_game.c	\
			restart.c


NAME	=	my_hunter

OBJ	=	$(SRC:.c=.o)

CFLAGS = -lcsfml-graphics	\
 		-lcsfml-window	\
		-lcsfml-system	\
		-lcsfml-audio	\
		-lm

all:	$(OBJ)
	gcc -o $(NAME) ${OBJ} include.h ${CFLAGS}

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
