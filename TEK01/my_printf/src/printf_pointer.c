/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-thomas.koebel
** File description:
** printf_pointer.c
*/

#include "my_printf.h"

void printf_pointer(va_list *arg_list, int *len)
{
    unsigned long nbr = va_arg(*arg_list, unsigned long);

    if ((void *)nbr == NULL)
        my_putstr("(nil)", len);
    else {
        my_putstr("0x", len);
        my_hexa(nbr, len);
    }
}
