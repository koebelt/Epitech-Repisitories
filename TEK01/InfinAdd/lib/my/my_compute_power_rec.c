/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** 
*/

int my_compute_power_rec(int nb, int power)
{
    if (nb > 2147483647 || nb < -2147483647)
        return (0);
    if (power > 2147483647 || power < 0)
        return (0);
    if (power == 0)
        return (1);
    if (power > 0)
        return (nb * (my_compute_power_rec(nb, power - 1)));
}
