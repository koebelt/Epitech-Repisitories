/*
** EPITECH PROJECT, 2019
** day 8
** File description:
** strdup
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (!str)
        return (NULL);
    for (; src[i]; i++)
        str[i] = src[i];
    str[i] = '\0';
    return (str);
}
