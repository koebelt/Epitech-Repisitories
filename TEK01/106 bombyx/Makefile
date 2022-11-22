##
## EPITECH PROJECT, 2021
## tests codes
## File description:
## Makefile
##

SRC    =    main.c \

OBJ    =    $(SRC:.c=.o)

NAME    =   106bombyx

bombyx : $(OBJ)
	gcc -o $(NAME) $(OBJ) -I include/
	rm -f $(OBJ)

all : bombyx

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

unit_tests : fclean