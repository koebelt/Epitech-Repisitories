/*
** EPITECH PROJECT, 2021
** B-AIA-200-STG-2-1-n4s-ethan.husser
** File description:
** my_strcat
*/

#include "../include/include.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    int a = 0;
    char *res;

    while (dest[i] != '\0')
        i += 1;
    while (src[j] != '\0')
        j += 1;
    res = malloc(sizeof(char) * (i + j + 1));
    i = 0;
    for (a = 0; dest[a] != '\0'; a += 1, ++i)
        res[i] = dest[a];
    for (a = 0; src[a] != '\0'; a += 1, ++i)
        res[i] = src[a];
    res[i] = '\0';
    return (res);
}
