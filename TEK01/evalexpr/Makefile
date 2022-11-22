##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

SRC 	=	eval_expr.c	\
		do_op.c	\
		main.c	\


NAME	=	eval_expr

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -I./include -L./lib -lmy -g

clean:
	rm -f *.o
	make clean -C lib/my

fclean:	clean
	rm -f $(NAME)
	rm -f lib/libmy.a

re:	fclean all
