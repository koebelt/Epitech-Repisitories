/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** displays a number
*/

#include "my_printf.h"

void my_put_nbr(int n, int *len)
{
    if (n == -2147483648) {
        my_putchar('-', len);
        my_putchar('2', len);
        n %= 1000000000;
        n *= -1;
    }
    if (n < 0) {
        my_putchar('-', len);
        n *= -1;
    }
    if (n < 10) {
        my_putchar(n + 48, len);
    } else {
        my_put_nbr(n / 10, len);
        my_putchar((n % 10) + 48, len);
    }
}

void my_put_unbr(unsigned int n, int *len)
{
    if (n < 10) {
        my_putchar(n + 48, len);
    } else {
        my_put_unbr(n / 10, len);
        my_putchar((n % 10) + 48, len);
    }
}
