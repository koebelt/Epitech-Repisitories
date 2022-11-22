/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** my_int_to_str.c
*/

#include "include.h"

int my_int_len(int n)
{
    int len = 0;

    while (n != 0) {
        len++;
        n /= 10;
    }
    return (len);
}

char *my_int_to_str(int num)
{
    int rem;
    int n = num;
    int len = my_int_len(n);
    char *str;

    str = malloc(sizeof(char) * (len + 1));
    if (num == 0) {
        str[0] = '0';
        len = 1;
    }
    for (int i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return(str);
}
