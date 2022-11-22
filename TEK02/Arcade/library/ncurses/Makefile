##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-arcade-thomas.koebel
## File description:
## Makefile
##


SRC_NCURSES = Ncurses.cpp

NCURSES_NAME	=	arcade_ncurses.so

RM	=	rm -rf

CC	=	g++

ncurses:
		$(CC) -Wall -fPIC -shared -lncurses -g -o $(NCURSES_NAME) $(SRC_NCURSES)
		mv $(NCURSES_NAME) ../../lib/$(NCURSES_NAME)

all: ncurses

clean:
	$(RM) $(NCURSES_OBJ)

fclean: clean
	$(RM) ../../lib/$(NCURSES_NAME)

re: fclean all clean

.PHONY: fclean clean all re ncurses