##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## make
##

SRC 	=	main.c	\
			find.c	\


NAME	=	bsq

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) -I./include -L./lib -lmy -g

clean:
	rm -f *.o
	make clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	rm -f ./lib/libmy.a

re:	fclean all
