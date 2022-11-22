/*
** EPITECH PROJECT, 2022
** B-PSU-400-STG-4-1-malloc-thomas.koebel
** File description:
** calloc
*/

#include "malloc.h"

void *calloc(size_t number, size_t size)
{
    char *new_str = malloc(number * size);

    size = number * size;
    if (!new_str)
        return (NULL);
    for (int i = 0; i < size; i++)
        new_str[i] = 0;
    return (new_str);
}