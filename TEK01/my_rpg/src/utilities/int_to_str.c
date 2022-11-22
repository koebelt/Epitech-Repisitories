/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** int_to_str
*/

#include "../../include/include.h"

int my_int_len(int n)
{
    int len = 0;

    while (n != 0) {
        len++;
        n /= 10;
    }
    return (len);
}

/* char *int_to_str(int num)
{
    int rem = 0;
    int n = num;
    int len = my_int_len(n);
    char *str = NULL;

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
} */

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char c;

    while (i < j) {
        c = str[j];
        str[j] = str[i];
        str[i] = c;
        i++;
        j--;
    }
    return (str);
}

char *int_to_str(long long nb)
{
    char *res = NULL;
    int i = 1;
    unsigned long long number;
    unsigned long long temp;

    number = nb < 0 ? -nb : nb;
    temp = number;
    for (; temp / 10 > 0 ; temp = temp / 10, i++);
    res = malloc(sizeof(char) * (i + (nb < 0 ? 2 : 1)));
    for (i = 0; number / 10 > 0; number = number / 10, i++)
        res[i] = number % 10 + '0';
    res[i] = number % 10 + '0';
    if (nb < 0) {
        i++;
        res[i] = '-';
    }
    res[i + 1] = '\0';
    return (my_revstr(res));
}