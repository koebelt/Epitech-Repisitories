/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** calc
*/

#include "include/my.h"
#include "include/bistro.h"
#include <stdlib.h>

char *get_number(char *expr)
{
    int len = 1;
    char *str;

    for (int i = 1; expr[i] >= '0' && expr[i] <= '9'; i++, len++);
    if (!(str = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    for	(int i = 0; i < len; i++)
        str[i] = expr[i];
    str[len] = '\0';
    return (str);
}

char *calc(char *expr, char *base)
{
    char *cpy = expr;
    char *a = get_number(expr);
    char op;
    char *res = NULL;

    if (!a)
        return (NULL);
    expr++;
    for (; *expr >= '0' && *expr <= '9'; expr++);
    op = *expr;
    expr += op == '-' && expr[1] != '-' ? 0 : 1;
    res = op == '+' || op == '-' ? infin_add(a, expr) : res;
    res = op == '*' ? infin_mul(a, expr) : res;
    res = op == '/' ? infin_div(a, expr) : res;
    res = op == '%' ? infin_mod(a, expr) : res;
    free(a);
    free(cpy);
    return (res);
}
