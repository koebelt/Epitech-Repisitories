/*
** EPITECH PROJECT, 2019
** day 4
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    long nbr = 0;
    int count = 0;
    int i = 0;
    int sign = 1;

    for (; str[i] == ' '; i++);
    for (; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; str[i] > 47 && str[i] < 58 && count < 11; i++) {
        nbr = nbr * 10 + str[i] - 48;
        count++;
    }
    nbr *= sign;
    if (nbr < -2147483648 || nbr > 2147483647)
        return (0);
    else
        return ((int)nbr);
}
