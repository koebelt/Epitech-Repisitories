/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** infin_sub
*/

#include "include/my.h"
#include "include/bistro.h"
#include <stdlib.h>

void calc_sub(char *x, char *y, char *str)
{
    int lenx = my_strlen(x);
    int leny = my_strlen(y);
    int a;
    int b;
    int i;
    int car = 0;

    for (i = 0; i < lenx || i < leny; i++) {
        a = lenx - i - 1 < 0 ? 0 : x[lenx - i - 1] - 48;
        b = leny - i - 1 < 0 ? 0 : y[leny - i - 1] - 48;
        str[i] = (a - b - car + 10) % 10 + 48;
        car = a - b - car < 0 ? 1 : 0;
    }
    str[i] = '\0';
}

int sign_detec_sub(char **x, char **y, int *big)
{
    int neg = *x[0] == '-' ? 0 : 1;
    int lenx;

    *x += !neg ? 1 : 0;
    *y += neg && *y[0] == '-' ? 1 : 0;
    for (; *x[0] == '0' && (*x)[1]; (*x)++);
    for (; *y[0] == '0' && (*y)[1]; (*y)++);
    if ((lenx = my_strlen(*x)) < my_strlen(*y)) {
        (*big)++;
        return (neg ? 1 : 0);
    } else if (lenx > my_strlen(*y))
        return (!neg ? 1 : 0);
    for (int i = 0; i < lenx; i++) {
        if ((*x)[i] < (*y)[i]) {
            (*big)++;
            return (neg ? 1 : 0);
        } else if ((*x)[i] > (*y)[i])
            return (!neg ? 1 : 0);
    }
    return (0);
}

char *sub_inf(char *x, char *y)
{
    char *str;
    int big = 0;
    int i;
    int sign = sign_detec_sub(&x, &y, &big);

    if (!big) {
        if (!(str = malloc(sizeof(char) * (my_strlen(x) + 1 + sign))))
            return (NULL);
    } else
        if (!(str = malloc(sizeof(char) * (my_strlen(y) + 1 + sign))))
            return (NULL);
    !big ? calc_sub(x, y, str) : calc_sub(y, x, str);
    for (i = my_strlen(str) - 1; str[i] == '0' && i > 0; i--)
        str[i] = '\0';
    if (my_strcmp(str, "0") && sign) {
        str[++i] = '-';
        str[++i] = '\0';
    }
    my_revstr(str);
    return (str);
}
