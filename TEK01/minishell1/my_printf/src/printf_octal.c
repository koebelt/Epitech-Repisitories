/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-thomas.koebel
** File description:
** printf_octal.c
*/

#include "my_printf.h"
#include <stdlib.h>

void printf_octal(va_list *arg_list, int *len)
{
    unsigned int dec = va_arg(*arg_list, unsigned int);
    char *octal = malloc(sizeof(char) * (dec + 1));

    if (dec < 8)
        my_put_nbr(dec, len);
    else {
        for(int i = 0; dec > 0; i++) {
            octal[i] = (dec % 8) + 48;
            dec = dec / 8;
        }
        my_putstr(my_revstr(octal), len);
    }
    free(octal);
}
