##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-arcade-thomas.koebel
## File description:
## Makefile
##

SRC_NIBBLER = Nibbler.cpp

NIBBLER_NAME	=	arcade_nibbler.so

RM	=	rm -rf

CC	=	g++

nibbler:
		$(CC) -Wall -fPIC -shared -g -o $(NIBBLER_NAME) $(SRC_NIBBLER)
		mv $(NIBBLER_NAME) ../../lib/$(NIBBLER_NAME)

all: menu

clean:
	$(RM) $(NIBBLER_OBJ)

fclean: clean
	$(RM) ../../lib/$(NIBBLER_NAME)

re: fclean all clean

.PHONY: fclean clean all re nibbler