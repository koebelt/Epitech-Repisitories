##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

SRC    =    pong.c \
			USAGE.c \
			error.c \

OBJ    =    $(SRC:.c=.o)

NAME    =    101pong

all : $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -I include/ -L lib/ -lmy -lm
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all