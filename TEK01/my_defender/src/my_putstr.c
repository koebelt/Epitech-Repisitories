/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** my_putstr
*/

#include "../include/include.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        write(1, &str[i], 1);
    }
}
