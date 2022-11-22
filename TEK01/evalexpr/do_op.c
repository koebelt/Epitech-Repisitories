/*
** EPITECH PROJECT, 2020
** do_op
** File description:
** do an operation with 2 numbers
*/

#include "include/my.h"

int verif_add(int nb1, int nb2, char op)
{
    int result = 0;

    if (op == '+')
        result = nb1 + nb2;
    else
        result = nb1 - nb2;
    return (result);
}

int verif_mult(int nb1, int nb2, char op)
{
    int result = 0;

    if (op != '*' && op != '/')
        result = verif_add(nb1, nb2, op);
    else if (op == '*')
        result = nb1 * nb2;
    else 
        result = nb1 / nb2;
    return (result);
}

int verif_modulo(int nb1, int nb2, char op)
{
    int result = 0;

    if (op != '%')
        result = verif_mult(nb1, nb2, op);
    else
        result = nb1 % nb2;
    return (result);
}

int operation(int nb1, int nb2, char op)
{
    return (verif_modulo(nb1, nb2, op));
}
