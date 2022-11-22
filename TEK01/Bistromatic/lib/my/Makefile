##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile of my lib
##

SRC     =	convert_base.c			\
		my_getnbr.c			\
		my_getnbr_base.c		\
		my_nbrcmp.c			\
		my_putchar.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_strcmp.c			\
		my_strdup.c			\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *~
