/*
** EPITECH PROJECT, 2020
** bitro matic
** File description:
** infin_mul
*/

#include "include/my.h"
#include "include/bistro.h"
#include <stdlib.h>

int calc_mul(char *x, char b, char *str, int i)
{
    int lenx = my_strlen(x);
    int a;
    int car = 0;

    for (int j = 0; j < lenx; j++, i++) {
        a = lenx - j - 1 < 0 ? 0 : x[lenx - j - 1] - 48;
        str[i] = (a * b + car) % 10 + 48;
        car = a * b + car < 10 ? 0 : (a * b + car) / 10;
    }
    if (car)
        str[i++] = car + 48;
    str[i] = '\0';
    return (i);
}

int tab_fill(char *x, char *y, char **tab, int sign)
{
    int j;
    int lenx = my_strlen(x);
    int leny = my_strlen(y);

    for (int i = 0; i < leny; i++) {
        if (!(tab[i] = malloc(sizeof(char) * (lenx + i + sign + 2))))
            return (0);
        for (j = 0; j < i; j++)
            tab[i][j] = '0';
        j = calc_mul(x, y[leny - i - 1] - 48, tab[i], j);
        if (sign) {
            tab[i][j++] = '-';
            tab[i][j] = '\0';
        }
        my_revstr(tab[i]);
    }
    tab[leny] = NULL;
    return (1);
}

char *end_of_mul(char **tab)
{
    char *str = infin_add(tab[0], "0");
    char *tmp1;

    if (!str)
        return (NULL);
    for (int i = 1; tab[i]; i++) {
        tmp1 = str;
        str = infin_add(tmp1, tab[i]);
        free(tmp1);
        if (!str)
            return (NULL);
    }
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    return (str);
}

int sign_detec_mul(char **x, char **y, int *big)
{
    int sign = 0;

    if (*x[0] == '-' && *y[0] == '-') {
        (*x)++;
        (*y)++;
    } else if (*x[0] == '-' || *y[0] == '-') {
        if (*x[0] == '-')
            (*x)++;
        else
            (*y)++;
        sign++;
    }
    for (; *x[0] == '0' && (*x)[1]; (*x)++);
    for	(; *y[0] == '0' && (*y)[1]; (*y)++);
    if (!my_strcmp(*x, "0") || !my_strcmp(*y, "0"))
        sign = 0;
    *big = my_strlen(*x) >= my_strlen(*y) ? 0 : 1;
    return (sign);
}

char *infin_mul(char *x, char *y)
{
    int big = 0;
    int sign = sign_detec_mul(&x, &y, &big);
    char **tab;
    int fail;

    if (!big) {
        if (!(tab = malloc(sizeof(char *) * (my_strlen(y) + 1))))
            return (NULL);
    } else
        if (!(tab = malloc(sizeof(char *) * (my_strlen(x) + 1))))
            return (NULL);
    fail = !big ? tab_fill(x, y, tab, sign) : tab_fill(y, x, tab, sign);
    if (!fail) {
        for (int i = 0; tab[i]; i++)
            free(tab[i]);
        free(tab);
        return (NULL);
    }
    return (end_of_mul(tab));
}
