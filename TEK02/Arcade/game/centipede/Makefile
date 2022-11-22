##
## EPITECH PROJECT, 2022
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

SRC_CENTIPEDE = Centipede.cpp

CENTIPEDE_NAME	=	arcade_centipede.so

RM	=	rm -rf

CC	=	g++

centipede:
		$(CC) -Wall -fPIC -shared -g -o $(CENTIPEDE_NAME) $(SRC_CENTIPEDE)
		mv $(CENTIPEDE_NAME) ../../lib/$(CENTIPEDE_NAME)

all: menu

clean:
	$(RM) $(CENTIPEDE_OBJ)

fclean: clean
	$(RM) ../../lib/$(CENTIPEDE_NAME)

re: fclean all clean

.PHONY: fclean clean all re centipede