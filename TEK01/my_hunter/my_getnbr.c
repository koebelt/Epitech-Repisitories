/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** my_getnbr.c
*/

int	my_getnbr(const char *str)
{
    int i = 0;
    int nbr = 0;

    while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
        i = i + 1;
    while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0') {
        nbr = ((nbr * 10) + (str[i] - '0'));
        i = i + 1;
    }
    if (str[0] == '-')
        nbr *= -1;
    return (nbr);
}
