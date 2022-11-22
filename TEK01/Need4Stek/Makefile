##
## EPITECH PROJECT, 2021
## n4s_package
## File description:
## Makefile
##


NAME	= ai

CC	= gcc

RM	= rm -f

CFLAGS	= -W -Wall -g


SRCS	=	src/ai.c	\
			src/ai_utils.c \
			src/my_str_to_tab.c	\
			src/my_strcat.c	\


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