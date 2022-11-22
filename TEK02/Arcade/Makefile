##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-arcade-thomas.koebel
## File description:
## Makefile
##

SRC    =    core/Core.cpp

OBJ = $(SRC:.cpp=.o)

NAME    =    arcade

RM    =    rm -rf

CC    =    g++

all: $(NAME)

core: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -g -ldl

games:
	make -C ./game/nibbler
	make -C ./game/centipede

graphicals:
	make -C ./library/ncurses
	make -C ./library/libcaca
	make -C ./library/SDL2

$(NAME): graphicals games core

clean:
	make -C ./library/ncurses clean
	make -C ./library/libcaca clean
	make -C ./library/SDL2 clean
	make -C ./game/nibbler clean
	make -C ./game/centipede clean
	$(RM) $(OBJ)

fclean: clean
	make -C ./library/ncurses fclean
	make -C ./library/libcaca fclean
	make -C ./library/SDL2 fclean
	make -C ./game/nibbler fclean
	make -C ./game/centipede fclean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean clean all re graphicals game core