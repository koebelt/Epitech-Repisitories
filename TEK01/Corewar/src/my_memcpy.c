/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thibaut.ruscher
** File description:
** my_memcpy
*/

#include "../include/header.h"

void *my_memcpy(void *p, void *content, size_t len)
{
    char *str = p;
    char *cpy = content;

    while (len--)
        *str++ = *cpy++;
    return (p);
}