/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** nbr cmp
*/

#include "../../include/my.h"

int my_nbrcmp(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (len1 != len2)
        return (len1 - len2);
    for (int i = 0; s1[i]; i++)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    return (0);
}
