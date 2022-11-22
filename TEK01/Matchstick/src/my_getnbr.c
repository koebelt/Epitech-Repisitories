/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-thomas.koebel
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int s = 1;
    int r = 0;
    int i = 0;

    if (str == 0)
        return (0);
    while ((*str < 47 || *str > 58) && *str != '\n') {
        str = str + 1;
        i = i + 1;
    }
    if (i > 0 && *(str - 1) == 45)
        s = -1;
    while (*str != '\n' && *str >= '0' && *str <= '9') {
        r = r * 10;
        r = r + *str - 48;
        str = str + 1;
    }
    r = r * s;
    return (r);
}
