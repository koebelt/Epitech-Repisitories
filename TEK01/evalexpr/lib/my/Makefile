##
## EPITECH PROJECT, 2020
## 
## File description:
## Makefile
##

SRC	=	my_putstr.c	\
		my_putchar.c	\
		my_swap.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_is_prime.c	\
		my_isneg.c	\
		my_put_nbr.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_sort_int_array.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_str_is_bigger.c	\
		my_str_is_lower.c	\
		my_strdup.c	\


NAME	=	test

OBJ	=	$(SRC:.c=.o)

all:	$(OBJ)
	ar rc libmy.a *.o
	mv libmy.a ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
