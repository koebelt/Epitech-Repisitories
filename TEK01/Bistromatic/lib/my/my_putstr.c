/*
** EPITECH PROJECT, 2019
** day 4
** File description:
** putstr
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}
