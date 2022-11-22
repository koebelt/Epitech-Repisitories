/*
** EPITECH PROJECT, 2020
** tests codes
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; i < my_strlen(str); i += 1) {
        res[i] = str[i];
    }
    return (res);
}