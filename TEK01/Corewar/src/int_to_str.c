/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** int_to_str
*/

#include <stdlib.h>
#include "../include/header.h"

char *my_revstr(char *str);

char *int_to_str(long long nb)
{
    char *res = NULL;
    int i = 1;
    unsigned long long number;
    unsigned long long temp;

    number = nb < 0 ? -nb : nb;
    temp = number;
    for (; temp / 10 > 0 ; temp = temp / 10, i++);
    res = malloc(sizeof(char) * (i + (nb < 0 ? 2 : 1)));
    for (i = 0; number / 10 > 0; number = number / 10, i++)
        res[i] = number % 10 + '0';
    res[i] = number % 10 + '0';
    if (nb < 0) {
        i++;
        res[i] = '-';
    }
    res[i + 1] = '\0';
    return (my_revstr(res));
}