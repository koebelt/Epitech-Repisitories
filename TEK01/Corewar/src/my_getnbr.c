/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thibaut.ruscher
** File description:
** my_getnbr
*/

#include "../include/header.h"

void my_putchar(char c);

long my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    long number = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0' && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    number *= neg;
    return (number);
}