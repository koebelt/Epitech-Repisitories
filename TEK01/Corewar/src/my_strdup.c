/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thibaut.ruscher
** File description:
** my_strdup
*/

#include "../include/header.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *str)
{
    char *back;

    back = malloc(sizeof(*back) * (my_strlen(str) + 1));
    if (back == NULL)
        return (back);
    my_strcpy(back, str);
    return (back);
}