##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-arcade-thomas.koebel
## File description:
## Makefile
##


SRC_LIBCACA = LibCaca.cpp

LIBCACA_NAME	=	arcade_libcaca.so

RM	=	rm -rf

CC	=	g++

libcaca:
		$(CC) -Wall  `pkg-config --libs --cflags caca` -fPIC -shared -g -o $(LIBCACA_NAME) $(SRC_LIBCACA)
		mv $(LIBCACA_NAME) ../../lib/$(LIBCACA_NAME)

all: libcaca

clean:
	$(RM) $(LIBCACA_OBJ)

fclean: clean
	$(RM) ../../lib/$(LIBCACA_NAME)

re: fclean all clean

.PHONY: fclean clean all re ncurses