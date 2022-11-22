/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** displays a number
*/

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
}
