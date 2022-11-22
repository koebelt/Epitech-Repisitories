/*
** EPITECH PROJECT, 2019
** day 6
** File description:
** reverse a string
*/


char *my_revstr(char *str)
{
    char tmp;
    int len = 0;

    for (; str[len]; len++);
    len--;
    for (int i = 0; i < len; i++) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        len--;
    }
    return (str);
}
