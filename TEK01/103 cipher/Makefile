##
## EPITECH PROJECT, 2020
## B-MAT-100-STG-1-1-102architect-matheo.vitali
## File description:
## Makefile
##

SRC =	cofactor.c \
		deter.c \
		inverse.c \
		main.c \
		multiply_matrix.c \
		my_getnbr.c \
		my_str_to_word_array.c \
		my_strlen.c	\
		str_to_matrix.c \
		transpose.c \
		usage.c \
		error_management.c \

OBJ = $(SRC:.c=.o)

NAME = 103cipher

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(OBJ) -o $(NAME) -lm -g
		rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
