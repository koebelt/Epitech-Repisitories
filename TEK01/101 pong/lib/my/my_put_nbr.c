/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday07-matheo.vitali
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int n)
{
    if (n == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        n %= 1000000000;
        n *= -1;
    }
    if (n < 0) {
        my_putchar('-');
        n *= -1;
    }
    if (n < 10) {
        my_putchar(n + 48);
    } else {
        my_put_nbr(n / 10);
        my_putchar((n % 10) + 48);
    }
    return (0);
}