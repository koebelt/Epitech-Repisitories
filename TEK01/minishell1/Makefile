##
## EPITECH PROJECT, 2021
## B-PSU-101-STG-1-1-minishell1-thomas.koebel
## File description:
## Makefile
##

SRC 	=	src/main.c	\
			src/my_str_to_word_array.c	\
			src/my_strcat.c	\
			src/my_strcmp.c	\
			src/my_strlen.c	\
			src/my_getnbr.c	\
			src/my_putchar.c	\
			src/my_putstr.c	\
			src/execute.c	\
			src/find_in_env.c	\
			src/integrated_commands.c	\
			src/prompt.c	\
			src/is_in_str.c	\



NAME	=	mysh

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	make -C ./my_printf
	$(CC) -o $(NAME) $(OBJ) -L ./my_printf -lmy

clean:
	rm -f src/*.o
	make -C ./my_printf clean

fclean:	clean
	rm -f $(NAME)
	make -C ./my_printf fclean

re:	fclean all
