/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-thomas.koebel
** File description:
** printf_hexa.c
*/

#include <stdlib.h>
#include "my_printf.h"

void printf_hexa(va_list *arg_list, int *len)
{
    unsigned int dec = va_arg(*arg_list, unsigned int);
    my_hexa(dec, len);
}

void printf_maj_hexa(va_list *arg_list, int *len)
{
    unsigned int dec = va_arg(*arg_list, unsigned int);
    my_maj_hexa(dec, len);
}
void my_hexa(unsigned long nb, int *len)
{
    unsigned long res;

    if (nb >= 16) {
        res = nb % 16;
        nb = nb / 16;
        my_hexa(nb, len);
    } else {
        res = nb % 16;
        nb = nb / 16;
    }
    if (res > 9)
        my_putchar(res + 87, len);
    else
        my_putchar(res + 48, len);
}

void my_maj_hexa(unsigned int nb, int *len)
{
    unsigned int res;

    if (nb >= 16) {
        res = nb % 16;
        nb = nb / 16;
        my_hexa(nb, len);
    } else {
        res = nb % 16;
        nb = nb / 16;
    }
    if (res > 9)
        my_putchar(res + 55, len);
    else
        my_putchar(res + 48, len);
}
