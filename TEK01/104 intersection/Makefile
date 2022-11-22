##
## EPITECH PROJECT, 2021
## B-MAT-100-STG-1-1-104intersection-matheo.vitali
## File description:
## Makefile
##

SRC    =	intersec.c

OBJ    =    $(SRC:.c=.o)

NAME    =	104intersection

all:    $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(OBJ) -lm
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re : fclean all