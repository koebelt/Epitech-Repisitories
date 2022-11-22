/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday07-matheo.vitali
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int a = 0;
    int nbr = 0;
    int ng = 0;

    while (str[a] != '\0') {
        if (str[a] == 43) {
            ++a;
        } else if (str[a] == 45) {
            ++ng;
            ++a;
        } else {
            nbr = nbr * 10 + (str[a] - 48);
            ++a;
        }
    }
    if (ng % 2 != 0) {
        nbr = nbr * -1;
    }
    return (nbr);
}