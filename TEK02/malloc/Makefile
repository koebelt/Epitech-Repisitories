##
## EPITECH PROJECT, 2022
## B-PSU-400-STG-4-1-malloc-thomas.koebel
## File description:
## Makefile
##

SRC	=	malloc.c	\
		free.c	\
		calloc.c	\
		realloc.c

NAME	=	libmy_malloc.so

RM	=	rm -rf

CC	=	gcc

RUN	=	test

all: $(NAME)

$(NAME):
		$(CC) -Wall -fPIC -shared -o $(NAME) $(SRC)

run:
		$(CC) main.c -o $(RUN)
		$(CC) -Wall -fPIC -shared -o $(NAME) $(SRC)
		LD_PRELOAD=./$(NAME) ./$(RUN)

clean:
	$(RM) $(OBJ)
	$(RM) $(LIB_SRC:.c=.o)

fclean: clean
	$(RM) $(RUN)
	$(RM) $(NAME)
	$(RM) $(LIBNAME)

re: fclean all clean

.PHONY: fclean clean all re run