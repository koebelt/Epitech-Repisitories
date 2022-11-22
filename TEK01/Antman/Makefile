##
## EPITECH PROJECT, 2021
## B-CPE-110-STG-1-1-antman-thomas.koebel
## File description:
## Makefile
##

NAME	=	allman

all :	$(NAME)

$(NAME):	$(OBJ)
	make -C ./antman all
	make -C ./giantman all

clean:
	make -C ./antman clean
	make -C ./giantman clean

fclean:	clean
	make -C ./antman fclean
	make -C ./giantman fclean

re:	fclean all clean