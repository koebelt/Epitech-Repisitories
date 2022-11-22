/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-thomas.koebel
** File description:
** knockoff of printf homemade
*/

#include "my_printf.h"

int index_finder(char *tab, char c)
{
    for (int i = 0; tab[i]; ++i)
        if (tab[i] == c)
            return (i);
    return(-1);
}

void find_right_fcn(char *str, int i, va_list *arg_list, int *len)
{
    void (*function_tab[12]) (va_list *, int *) = {printf_char, printf_char,
        printf_str, printf_nstr, printf_nbr, printf_nbr, printf_octal, printf_hexa,
        printf_maj_hexa, printf_unbr, printf_pointer, printf_bin};
    char index_tab[13] = {'c', 'C', 's', 'S', 'd', 'i', 'o', 'x', 'X', 'u',
    'p', 'b', 0};
    int index = 0;

    if (i > 0 && str[i - 1] == '%') {
        index = index_finder(index_tab, str[i]);
        if (index != -1)
            (*function_tab[index]) (arg_list, len);
    } else if (str[i] != '%')
        my_putchar(str[i], len);
}

int my_printf(char *str, ...)
{
    int len = 0;
    va_list arg_list;

    va_start(arg_list, str);
    for (int i = 0; str[i]; ++i) {
        find_right_fcn(str, i, &arg_list, &len);
    }
    va_end(arg_list);
    return (len);
}
