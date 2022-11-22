##
## EPITECH PROJECT, 2021
## B-CPE-201-STG-2-1-corewar-thibaut.ruscher
## File description:
## Makefile
##

SRC		=	$(wildcard ../src/*.c)	\
			$(wildcard ./*.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	=	-Wall \
			-Werror	\
			-g

CC		=	gcc

RM		=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		make clean

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re