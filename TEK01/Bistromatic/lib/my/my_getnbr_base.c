/*
** EPITECH PROJECT, 2020
** day 6
** File description:
** getnbr base
*/

int my_getnbr_base(char const *str, char const *base)
{
    long nbr = 0;
    int len_b = 0;
    int i = 0;
    int j = 0;
    int sign = 1;

    for (; base[len_b]; len_b++);
    for (; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; str[i]; i++) {
        for (j = 0; base[j] != str[i] && base[j]; j++);
        if (!base[j])
            return (0);
        nbr = nbr * len_b + j;
    }
    nbr *= sign;
    return (nbr < -2147483648 || nbr > 2147483647 ? 0 : (int)nbr);
}
