/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** my_put_nbr
*/

#include "../include/antman.h"

void my_put_nbr(int n)
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
}
