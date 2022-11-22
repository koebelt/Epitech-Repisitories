##
## EPITECH PROJECT, 2022
## B-PSU-400-STG-4-1-malloc-thomas.koebel
## File description:
## Makefile
##

SRC	=	src/strlen.asm	\
		src/strchr.asm	\
		src/strrchr.asm	\
		src/memset.asm	\
		src/memcpy.asm	\
		src/strcmp.asm	\
		src/strncmp.asm	\
		src/strcasecmp.asm	\
		src/strstr.asm	\
		src/strpbrk.asm	\
		src/strcspn.asm


OBJ = $(SRC:.asm=.o)

NAME	=	libasm.so

RM	=	rm -rf

CC	=	gcc

ASM = nasm

RUN	=	test

all: $(NAME)

%.o: %.asm
	$(ASM) -o $@ $< -f elf64

$(NAME):	$(OBJ)
		ld -shared -o $(NAME) $(OBJ)

run:	$(OBJ)
		$(CC) -fno-builtin main.c -o $(RUN)
		ld -shared -o $(NAME) $(OBJ)
		LD_PRELOAD=./$(NAME) ./$(RUN)

clean:
	$(RM) $(OBJ)
	$(RM) $(LIB_SRC:.c=.o)

fclean: clean
	$(RM) $(RUN)
	$(RM) $(NAME)
	$(RM) $(LIBNAME)

re: fclean all clean

.PHONY: fclean clean all re run