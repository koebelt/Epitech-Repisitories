/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** infin add
*/

#include "include/my.h"
#include "include/bistro.h"
#include <stdlib.h>

void calc_add(char *x, char *y, char *str, int sign)
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
        str[i] = (a + b + car) % 10 + 48;
        car = a + b + car > 9 ? 1 : 0;
    }
    if (car)
        str[i++] = '1';
    if (sign)
        str[i++] = '-';
    str[i] = '\0';
}

char *add_inf(char *x, char *y, int sign)
{
    char *str;
    int lenx;
    int leny;

    for (; x[0] == '0' && x[1]; x++);
    for (; y[0] == '0' && y[1]; y++);
    if (!my_strcmp(x, "0") && !my_strcmp(y, "0"))
        sign = 0;
    if ((lenx = my_strlen(x)) >= (leny = my_strlen(y))) {
        if (!(str = malloc(sizeof(char) * (lenx + 2 + sign))))
            return (NULL);
    } else
        if (!(str = malloc(sizeof(char) * (leny + 2 + sign))))
            return (NULL);
    calc_add(x, y, str, sign);
    my_revstr(str);
    return (str);
}

char *infin_add(char *x, char *y)
{
    char *str;

    if (x[0] == '-' && y[0] == '-') {
        x++;
        y++;
        if (!(str = add_inf(x, y, 1)))
            return (NULL);
    } else if (x[0] == '-' || y[0] == '-') {
        if ((!my_strcmp(x, "0") || !my_strcmp(y, "0")) &&
            !(str = add_inf(x, y, 0)))
            return (NULL);
        else if (!(str = sub_inf(x, y)))
            return (NULL);
    } else
        if (!(str = add_inf(x, y, 0)))
            return (NULL);
    return (str);
}
