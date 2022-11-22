##
## EPITECH PROJECT, 2021
## B-CPE-200-STG-2-1-matchstick-thomas.koebel
## File description:
## Makefile
##

NAME	= matchstick

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall


SRCS	=	src/main.c \
			src/my_getnbr.c	\
			src/my_int_to_str.c	\
			src/my_strlen.c	\
			src/ai.c	\
			src/ai_utilities.c	\
			src/board.c	\
			src/player.c	\
			src/player_input.c	\



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