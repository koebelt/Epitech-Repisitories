##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-arcade-thomas.koebel
## File description:
## Makefile
##


SRC_SDL2 = SDL2.cpp

SDL2_NAME	=	arcade_sdl2.so

RM	=	rm -rf

CC	=	g++

sdl2:
		$(CC) -Wall -lSDL2main -lSDL2_image -lSDL2_ttf -lSDL2 -fPIC -shared -g -o $(SDL2_NAME) $(SRC_SDL2)
		mv $(SDL2_NAME) ../../lib/$(SDL2_NAME)

all: sdl2

clean:
	$(RM) $(SDL2_OBJ)

fclean: clean
	$(RM) ../../lib/$(SDL2_NAME)

re: fclean all clean

.PHONY: fclean clean all re ncurses