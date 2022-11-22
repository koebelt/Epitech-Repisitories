/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** infin mod
*/

#include "include/my.h"
#include "include/bistro.h"
#include <stdlib.h>

char *calc_mod(char *x, char *y, char *result, int i)
{
    char *div = infin_div(x, y);
    char *mult;
    char *rest;

    if (!div || !(mult = infin_mul(div, y)) || !(rest = sub_inf(x, mult)))
        return (NULL);
    if (rest[0] == '0' && i)
        result[0] = '0';
    else
        for (int j = 0; rest[j]; ++j, ++i)
            result[i] = rest[j];
    result[i] = '\0';
    free(rest);
    free(mult);
    free(div);
    return (result);
}

int sign_detec_mod(char **x, char **y)
{
    int sign = 0;

    if (*x[0] == '-') {
        sign++;
        (*x)++;
    }
    *y[0] == '-' ? (*y)++ : 0;
    for (; *x[0] == '0' && (*x)[1]; (*x)++);
    for (; *y[0] == '0' && (*y)[1]; (*y)++);
    return (sign);
}

char *infin_mod(char *x, char *y)
{
    int sign = sign_detec_mod(&x, &y);
    char *str;
    int leny = my_strlen(y);
    int i = 0;

    if (!(str = malloc(sizeof(char) * (leny + 1 + sign))))
        return (NULL);
    sign ? str[i++] = '-' : 0;
    if (!my_strcmp(y, "0") || !calc_mod(x, y, str, i)) {
        my_putstr("syntax error\n");
        free(str);
        return (NULL);
    }
    return (str);
}
