/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** my_strcmp
*/

#include "../../include/include.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i += 1) {
        if (s1[i] != s2[i])
            return (0);
    }
    if (s1[i] != '\0' || s2[i] != '\0')
        return (0);
    return (1);
}