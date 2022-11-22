##
## EPITECH PROJECT, 2021
## Untitled (Workspace)
## File description:
## Makefile
##

NAME	= matchstick

all :	$(NAME)

$(NAME):	$(OBJ)
	make -C ./generator all
	make -C ./solver all

clean:
	make -C ./generator clean
	make -C ./solver clean

fclean:	clean
	make -C ./generator fclean
	make -C ./solver fclean

re: fclean all

.PHONY: fclean clean all re