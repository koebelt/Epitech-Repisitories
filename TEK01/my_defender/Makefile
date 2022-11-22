##
## EPITECH PROJECT, 2021
## B-MUL-200-STG-2-1-mydefender-ethan.husser
## File description:
## Makefile
##

SRC 	=	src/sprite_utilities.c	\
			src/sprite_utilities2.c \
			src/main.c	\
			src/menu.c	\
			src/menu2.c \
			src/menu3.c \
			src/menu4.c \
			src/game.c	\
			src/game2.c \
			src/soldiers.c	\
			src/target_algorithm.c	\
			src/target_algorithm2.c \
			src/target_algorithm3.c \
			src/ig_ui.c	\
			src/ig_ui2.c \
			src/energy_system.c	\
			src/my_int_to_str.c	\
			src/buildings.c	\
			src/buildings2.c	\
			src/projectile.c	\
			src/projectile2.c \
			src/pause.c	\
			src/level_selection.c	\
			src/level_selection2.c \
			src/level_selection3.c \
			src/enemy_ai.c	\
			src/win.c	\
			src/player.c	\
			src/loose.c	\
			src/shop.c	\
			src/shop2.c \
			src/choose_tower.c	\
			src/choose_tower2.c	\
			src/my_getnbr.c	\
			src/my_strcat.c	\
			src/my_str_to_word_array.c	\
			src/my_strlen.c	\
			src/save.c	\
			src/randomize.c	\
			src/how_to_play.c \
			src/my_putstr.c \



NAME	=	my_defender

OBJ	=	$(SRC:.c=.o)

CFLAGS = 	-lcsfml-graphics	\
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
