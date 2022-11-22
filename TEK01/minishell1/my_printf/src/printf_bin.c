/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-thomas.koebel
** File description:
** printf_bin.c
*/

#include "my_printf.h"

void printf_bin(va_list *arg_list, int *len)
{
    unsigned int nb = va_arg(*arg_list, unsigned int);

    my_binary(nb, len);
}

void	my_binary(unsigned int nb, int *len)
{
    int	res;

    if (nb >= 2) {
        res = nb % 2;
        nb = nb / 2;
        my_binary(nb, len);
    } else if (nb > 0) {
        res = nb % 2;
        nb = nb / 2;
    }
    my_putchar(res + 48, len);
}
