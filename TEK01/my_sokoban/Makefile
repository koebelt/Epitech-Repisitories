##
## EPITECH PROJECT, 2021
## B-PSU-200-STG-2-1-mysokoban-thomas.koebel
## File description:
## Makefile
##

NAME	= my_sokoban

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -lncurses


SRCS	=	src/main.c \
			src/read_map.c	\
			src/my_str_to_word_array.c	\
			src/my_strlen.c	\
			src/is_in_str.c	\
			src/my_strcmp.c	\
			src/mvmnt.c	\
			src/loose.c	\
			src/map.c


OBJ   	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re