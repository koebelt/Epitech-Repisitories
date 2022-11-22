/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-thomas.koebel
** File description:
** printf_char.c
*/

#include "my_printf.h"

void printf_char(va_list *arg_list, int *len)
{
    char c = va_arg(*arg_list, int);

    my_putchar(c, len);
}

void printf_str(va_list *arg_list, int *len)
{
    char *str = va_arg(*arg_list, char *);

    my_putstr(str, len);
}

void printf_nstr(va_list *arg_list, int *len)
{
    char *str = va_arg(*arg_list, char *);

    for (int i = 0; str[i]; ++i) {
        if (str[i] < 32 || str[i] == 127)
            my_putchar(92, len);
        else
            my_putchar(str[i], len);
    }
}
