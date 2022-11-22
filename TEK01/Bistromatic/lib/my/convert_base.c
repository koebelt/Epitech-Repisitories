/*
** EPITECH PROJECT, 2020
** day 8
** File description:
** convert base
*/

#include <stdlib.h>
#include "../../include/my.h"

int fill_str(char *str, int n, char const *base_to, int len)
{
    int base = my_strlen(base_to);

    if (n >= base)
        fill_str(str, n / base, base_to, len - 1);
    str[len] = base_to[n % base];
    return (0);
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int n = my_getnbr_base(nbr, base_from);
    char *str;
    int len = 0;
    int base = my_strlen(base_to);
    int sign = 0;

    if (n < 0) {
        n *= -1;
        sign++;
        len++;
    }
    for (int cpy = n; cpy > 0; len++)
        cpy /= base;
    if (!(str = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    if (sign)
        str[0] = '-';
    fill_str(str, n, base_to, len  - 1);
    str[len] = '\0';
    return (str);
}
