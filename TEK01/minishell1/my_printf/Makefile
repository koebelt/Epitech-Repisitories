##
## EPITECH PROJECT, 2020
## Makefile
## File description:
##
##

SRC 	=	src/my_putchar.c	\
			src/my_putstr.c	\
			src/my_revstr.c	\
			src/my_put_nbr.c	\
			src/my_strlen.c	\
			src/my_printf.c	\
			src/printf_nbr.c	\
			src/printf_char.c	\
			src/printf_hexa.c	\
			src/printf_octal.c	\
			src/printf_bin.c	\
			src/printf_pointer.c	\



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
