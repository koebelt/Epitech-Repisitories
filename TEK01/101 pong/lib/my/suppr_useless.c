/*
** EPITECH PROJECT, 2020
** tests codes
** File description:
** suppr_zeros
*/

#include <stdlib.h>
#include "my.h"

char *supr_space(char *str)
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    int a = 0;

    if (!str2)
        return (NULL);
    for (int i = 0; i <= my_strlen(str); i += 1) {
        if (str[i] != ' ') {
            str2[a] = str[i];
            a += 1;
        }
    }
    return (str2);
}

char *suppr_useless(char *str)
{
    int ng = 0;

    for (int i = 0; i < my_strlen(str); i += 1) {
        if (str[i] == '+')
            str[i] = ' ';
        else if (str[i] == '-') {
            str[i] = ' ';
            ng += 1;
        }
    }
    for (int i = 0; !(str[i] <= '9' && str[i] >= '1'); i += 1) {
        if (str[i] == '0')
            str[i] = ' ';
    }
    if (ng % 2 != 0)
        str[0] = '-';
    str = supr_space(str);
    return (str);
}