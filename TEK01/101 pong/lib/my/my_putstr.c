/*
** EPITECH PROJECT, 2020
** mu_putstr.c
** File description:
** a function that displays the characters of a string
*/

#include "my.h"

int my_putstr(char const *str)
{    
    int i = 0;
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i += 1;
    }
}