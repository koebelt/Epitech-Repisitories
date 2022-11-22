/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** error_management.c
*/

#include "include.h"

int error_management(int ac, char **av)
{
    if (ac != 4)
        return (84);
    if ((av[3][0] != '1' && av[3][0] != '0') || av[3][1] != '\0')
        return (84);
    if (my_strlen(av[2]) > 9)
        return (84);
    return (0);
}
