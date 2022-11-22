/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-evalexpr-matheo.vitali
** File description:
** number
*/

int number(char *str)
{
    int a = 0;
    int nbr = 0;
    int ng = 0;

    while (str[a] < '0' || str[a] > '9') {
        if (str[a] == 43)
            ++a;
        else if (str[a] == 45) {
            ++ng;
            ++a;
        } else
            a++;
    }
    while (str[a] >= '0' && str[a] <= '9') {
        nbr = nbr * 10 + str[a] - 48;
        ++a;
    }
    if (ng % 2 != 0)
        nbr = nbr * -1;
    return (nbr);
}