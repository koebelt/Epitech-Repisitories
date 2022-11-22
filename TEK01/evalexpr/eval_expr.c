/*
** EPITECH PROJECT, 2020
** evalexpr
** File description:
** non lib fonction for evalexpr
*/

#include "include/my.h"

int while_parse(char **equat, int nbr, int signe)
{
    while('0' <= *equat[0] && *equat[0] <= '9') {
        nbr = (nbr * 10) + *equat[0] - '0';
        *equat = *equat +1;
    }
    return (signe * nbr);
}

int my_parse_nbr(char **equat) 
{
    int nbr;
    int signe;

    nbr = 0;
    signe = 1;
    if (*equat[0] == '+' || *equat[0] == '-') {
        if (*equat[0] == '-')
            signe = -1;
        *equat = *equat + 1;
    }
    if (*equat[0] == '(') {
        *equat = *equat + 1;
        nbr = eval_expr_add(equat);
        if (*equat[0] == ')')
            *equat = *equat + 1;
        return (signe * nbr);
    }
    return(while_parse(equat, nbr, signe));
}

int eval_expr_mult(char **equat)
{
    int nb1;
    int nb2;
    char op;

    nb1 = my_parse_nbr(equat);
    while (*equat[0] == '*' || *equat[0] == '/' || *equat[0] == '%')
    {
        op = *equat[0];
        *equat = *equat + 1;
        nb2 = my_parse_nbr(equat);
        nb1 = operation(nb1, nb2, op);
    }
    return (nb1);
}

int eval_expr_add(char **equat)
{
    int	nb1;
    int	nb2;
    char op;

    nb1 = my_parse_nbr(equat);
    while (*equat[0] != '\0' && *equat[0] != ')')
    {
        op = *equat[0];
        *equat = *equat + 1;
        if (op == '+' || op == '-')
            nb2 = eval_expr_mult(equat);
        else
            nb2 = my_parse_nbr(equat);
        nb1 = operation(nb1, nb2, op);
    }
    return (nb1);
}

int eval_expr(char *equation)
{
    if (equation[0] == '\0')
        return (0);
    return (eval_expr_add(&equation));
}
