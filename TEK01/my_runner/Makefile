##
## EPITECH PROJECT, 2020
## B-MUL-100-STG-1-1-myhunter-thomas.koebel
## File description:
## Makefile
##

SRC 	=	src/audio.c	\
			src/collisions.c	\
			src/compute_collisions.c	\
			src/death.c	\
			src/disp_layers.c	\
			src/display_map.c	\
			src/game.c	\
			src/hero.c	\
			src/init_layers.c	\
			src/jump.c	\
			src/load_map.c	\
			src/main.c	\
			src/menu_bottons.c	\
			src/menu.c	\
			src/my_putchar.c	\
			src/my_putstr.c	\
			src/my_str_to_word_array.c	\
			src/renit_layers.c	\
			src/renit.c	\
			src/reset_save.c	\
			src/quit.c	\
			src/select.c	\
			src/my_strcat.c	\
			src/my_int_to_str.c	\
			src/percent_bar.c	\
			src/my_getnbr.c	\
			src/save.c	\
			src/win.c	\
			src/init_layer_part_two.c	\
			src/init_layer_part_three.c	\
			src/load_obs.c	\
			src/load_obs_2.c


NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)

CFLAGS = -lcsfml-graphics	\
 		-lcsfml-window	\
		-lcsfml-system	\
		-lcsfml-audio	\
		-lm

all:	$(OBJ)
	gcc -o $(NAME) ${OBJ} ${CFLAGS}
	make clean

clean:
	rm -f src/*.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
