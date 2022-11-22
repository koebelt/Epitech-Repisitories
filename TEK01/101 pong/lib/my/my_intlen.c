/*
** EPITECH PROJECT, 2020
** tests codes
** File description:
** my_intlen
*/

int my_intlen(int nbr)
{
    int res = 0;

    while(nbr > 0) {
        nbr = nbr / 10;
        res += 1;
    }
    return (res);
}
