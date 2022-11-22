##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	= solver

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -g


SRCS	=	src/main.c	\
			src/my_str_to_tab.c	\
			src/path.c	\
			src/utils.c \



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