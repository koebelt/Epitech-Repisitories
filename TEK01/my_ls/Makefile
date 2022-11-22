##
## EPITECH PROJECT, 2020
## B-PSU-100-STG-1-1-myls-thomas.koebel
## File description:
## Makefile
##

SRC 	=	main.c	\
			my_strlen.c	\
			base_disp.c	\
			utilities.c	\
			long.c	\
			my_putchar.c	\
			my_nbr_len.c	\
			my_strcat.c	\
			time.c

NAME	=	my_ls

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) libmy.a

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
