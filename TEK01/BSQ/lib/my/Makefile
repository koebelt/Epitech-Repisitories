##
## EPITECH PROJECT, 2020
##
## File description:
## Makefile
##

SRC	=	my_putstr.c	\
		my_putchar.c	\
		my_strlen.c	\
		my_str_to_word_array.c	\
		my_tab_size.c


NAME	=	test

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	ar rc libmy.a *.o
	mv libmy.a ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
