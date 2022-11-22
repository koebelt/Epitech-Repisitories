##
## EPITECH PROJECT, 2021
## B-CPE-110-STG-1-1-antman-thomas.koebel
## File description:
## Makefile
##

NAME	= antman

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall


SRCS	=	src/open_file.c \
			src/main.c \
			src/is_in_str.c \
			src/indexs.c \
			src/tab_length.c \
			src/my_strcmp.c \
			src/my_str_to_word_array.c \
			src/my_putstr.c \
			src/my_put_nbr.c \
			src/my_strlen.c	\

OBJ   	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean all re
