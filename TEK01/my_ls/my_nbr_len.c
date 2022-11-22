/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** my_nbr_len.c
*/

#include "include.h"

int my_nbr_len(int nbr)
{
    int len = 0;

    if (nbr == 0)
        return (1);
    while (nbr > 0) {
        nbr = nbr / 10;
        ++len;
    }
    return (len);
}
