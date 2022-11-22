/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** eval expr
*/

#include "include/my.h"
#include "include/bistro.h"
#include <stdlib.h>

char *add_rec(char *str, char *base)
{
    char *res;
    int a = 0;
    int b = 0;

    add_pos(str, &a, &b);
    if (!(res = small_strdup(str, a, b)) || !(res = calc(res, base)))
        return (NULL);
    if (!(str = insert_result(str, res, a, b)))
        return (NULL);
    for (int i = 1; str[i]; i++)
        if (str[i] == '+' || str[i] == '-') {
            str = add_rec(str, base);
            break;
        }
    return (str);
}

char *prod_rec(char *str, char *base)
{
    char *res;
    int a = 0;
    int b = 0;

    prod_pos(str, &a, &b);
    if (!(res = small_strdup(str, a, b)) || !(res = calc(res, base)))
        return (NULL);
    if (!(str = insert_result(str, res, a, b)))
        return (NULL);
    for (int i = 0; str[i]; i++)
        if (str[i] == '*' || str[i] == '/' || str[i] == '%') {
            str = prod_rec(str, base);
            break;
        }
    return (str);
}

char *call_rec(char *res, char *base)
{
    for (int i = 0; res && res[i]; i++)
        if (res[i] == '*' || res[i] == '/' || res[i] == '%') {
            res = prod_rec(res, base);
            break;
        }
    for (int i = 1; res && res[i]; i++)
        if (res[i] == '+' || res[i] == '-') {
            res = add_rec(res, base);
            break;
        }
    return (res);
}

char *par_rec(char *str, char *base)
{
    char *res;
    int a = 0;
    int b = 0;

    par_pos(str, &a, &b);
    if (!(res = small_strdup(str, a + 1, b - 1)))
        return (NULL);
    for (int i = 0; res && res[i]; i++)
        if (res[i] == '(') {
            res = par_rec(res, base);
            i = 0;
        }
    res = call_rec(res, base);
    return (res ? insert_result(str, res, a, b) : NULL);
}

char *eval_expr(char *str, char *base)
{
    for (int i = 0; str && str[i]; i++)
        if (str[i] == '(') {
            str = par_rec(str, base);
            i = 0;
        }
    str = call_rec(str, base);
    return (str);
}
