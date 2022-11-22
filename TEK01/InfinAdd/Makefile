##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

SRC 	=	add.c	\
		sub.c	\
		main.c	\



NAME	=	infin_add

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -I./include -L./lib -lmy -g

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
