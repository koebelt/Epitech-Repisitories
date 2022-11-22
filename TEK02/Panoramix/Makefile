##
## EPITECH PROJECT, 2022
## B-CCP-400-STG-4-1-panoramix-thomas.koebel
## File description:
## Makefile
##

SRC	=	panoramix.c	\
		error_management.c


NAME	=	panoramix

OBJ = $(SRC:.c=.o)

RM	=	rm -rf

CC	=	gcc

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -Wall -lpthread -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean clean all re run