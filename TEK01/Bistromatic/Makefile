##
## EPITECH PROJECT, 2020
## bistro matic
## File description:
## Makefile
##

OBJ	=	$(SRC:.c=.o)

SRC	=	main.c			\
		errors.c		\
		eval_expr.c		\
		calc.c			\
		positions.c		\
		str_management.c	\
		infin_mul.c		\
		infin_add.c		\
		infin_sub.c		\
		infin_div.c		\
		infin_mod.c

NAME	=	calc

all :	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	gcc -o $(NAME) $(OBJ) -L ./lib/my -lmy

clean:
	rm -f $(OBJ)
	make -C ./lib/my clean

fclean:	clean
	make -C ./lib/my fclean
	rm -f $(NAME)
	rm -f *~

re:	fclean all clean

debug:	$(OBJ)
	gcc -Wall -g -o $(NAME) $(OBJ) -L ./lib/my -lmy
