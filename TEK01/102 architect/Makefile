##
## EPITECH PROJECT, 2020
## B-MAT-100-STG-1-1-102architect-matheo.vitali
## File description:
## Makefile
##

SRC =	src/main.c	\
		src/matrix.c	\
		src/operations.c	\
		src/str_to.c	\
		src/error.c    \
		src/float_check.c    \

OBJ = $(SRC:.c=.o)

NAME = 102architect

all:     $(NAME)

$(NAME): $(OBJ)
		gcc $(OBJ) -o $(NAME) -lm -g
		rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
