##
## EPITECH PROJECT, 2022
## Plazza
## File description:
## Makefile
##

SRC		=	main.cpp \
			./src/Cook.cpp \
			./src/Kitchen.cpp \
			./src/Reception.cpp \
			./src/Stock.cpp \
			./src/food/Pizza.cpp \
			./src/process/Serialization.cpp	\
			./src/utils/Logger.cpp

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -rf

NAME	=	plazza

CC		=	g++

FLAGS	=	-Wall \
			-Werror \
			-pthread

all: $(NAME)

$(NAME): $(OBJ)
		mkdir -p log
		mkdir -p fifo
		$(CC) -o $(NAME) $(OBJ) $(FLAGS)
		make clean

clean:
		$(RM) $(OBJ)
		$(RM) fifo/*

fclean: clean
		$(RM) $(NAME)
		$(RM) log

re: fclean all

.PHONY: all clean fclean re