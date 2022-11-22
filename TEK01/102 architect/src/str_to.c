/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-102architect-matheo.vitali
** File description:
** str_to.c
*/

#include "include.h"

int str_to_int(char *nbr)
{
    int res = 0;
    int neg = 0;

    if (*nbr == '-') {
        nbr += 1;
        neg += 1;
    }
    for (int i = 0; nbr[i] != '\0'; i += 1) {
        res = res * 10;
        res += nbr[i] - 48;
    }
    if (neg > 0)
        res = res * -1;
    return (res);
}

float str_to_float(char *nbr)
{
    float res = 0.00;
    int neg = 0;

    if (*nbr == '-') {
        nbr += 1;
        neg += 1;
    }
    for (int i = 0; nbr[i] != '\0'; i += 1) {
        res = res * 10;
        res += nbr[i] - 48;
    }
    if (neg > 0)
        res = res * -1;
    return (res);
}
