/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** 
*/

int my_compute_square_root(int nb)
{
    int b = 0;

    if (nb < 0)
        return (0);
    while (b * b != nb) {
        if (b * b > nb) {
            return (0);
        } else
            b += 1;
    }
    return (b);
}