/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"

char* my_strdup(char* str)
{
    int len;
    char* dup;

    len = my_strlen(str) + 1;
    dup = malloc(len);
    if(dup == 0)
        return (0);
    dup = my_strcpy(dup, str);
    dup[len - 1] = '\0';
    return (dup);
}
