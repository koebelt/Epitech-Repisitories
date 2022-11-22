##
## EPITECH PROJECT, 2022
## $
## File description:
## Makefile
##

SRC    =    main.cpp	\
			ComponentFactory.cpp	\
			Components/*.cpp	\

NAME    =    nanotekspice

RM    =    rm -rf

CC    =    g++

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) -g

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(RUN)
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean clean all re run