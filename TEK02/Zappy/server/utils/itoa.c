/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** itoa
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *my_revstr(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;
    char c = 0;

    while (i < j) {
        c = str[j];
        str[j] = str[i];
        str[i] = c;
        i++;
        j--;
    }
    return (str);
}

char *itoa(long long nb)
{
    char *res = NULL;
    int i = 1;
    unsigned long long number = 0;
    unsigned long long temp = 0;

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
