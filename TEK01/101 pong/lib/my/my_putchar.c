/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday07-matheo.vitali
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}