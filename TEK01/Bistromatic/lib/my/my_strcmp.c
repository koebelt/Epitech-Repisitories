/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare 2 string
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
