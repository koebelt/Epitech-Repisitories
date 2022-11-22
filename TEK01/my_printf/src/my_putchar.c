/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** Print a single character
*/

#include <unistd.h>

void my_putchar(char c, int *len)
{
    *len += 1;
    write(1, &c, 1);
}
