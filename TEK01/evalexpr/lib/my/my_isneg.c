/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Display either a given number is positive or negative
*/

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');   
}
