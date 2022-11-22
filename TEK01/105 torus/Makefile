##
## EPITECH PROJECT, 2021
## B-PSU-101-STG-1-1-minishell1-thomas.koebel
## File description:
## Makefile
##

SRC 	=	105torus.c

NAME	=	105torus

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm
	rm -f $(OBJ)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
