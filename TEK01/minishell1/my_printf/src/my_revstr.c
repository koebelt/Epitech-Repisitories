/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** 
*/

char *my_revstr(char *str)
{
    int i = 0;
    int b = 0;
    char c;

    while (str[i] != '\0')
        i += 1;
    i -= 1;
    while (i > b) {
        c = str[i];
        str [i] = str[b];
        str [b] = c;
        i -= 1;
        b += 1;
    }
    return (str);
}