/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** infin div
*/

#include "include/my.h"
#include "include/bistro.h"
#include <stdlib.h>

char *calc_div_2(char *nb1, char *nb2, char *to_div, int itr2)
{
    int itr = 0;
    char *sub;
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + 1));
    int res_len = my_strlen(nb1) - (itr2 - 1);

    if (!result)
       return (NULL);
    for (int i = 0; i < res_len; ++i) {
        sub = sub_inf(to_div, nb2);
        for (itr = 0; sub[0] != '-'; ++itr) {
            free(sub);
            sub = sub_inf(to_div, nb2);
            to_div = sub[0] != '-' ? sub_inf(to_div, nb2) : to_div;
        }
        result[i] = itr != 0 ? (itr - 1) + 48 : '0';
        (to_div[0] != '0') ? (to_div[my_strlen(to_div)] = nb1[++itr2 - 1])
            : (to_div[0] = nb1[++itr2 - 1]);
    }
    result[res_len] = '\0';
    return (result);
}

char *calc_first_div(char *nb1, char *nb2, int *itr2)
{
    char *to_div = malloc(sizeof(char) * (my_strlen(nb1) + 1));
    char *sub;

    if (!to_div)
        return (NULL);
    to_div[0] = nb1[0];
    to_div[1] = '\0';
    sub = sub_inf(to_div, nb2);
    for (*itr2 = 1; sub[0] == '-'; ++(*itr2)) {
        free(sub);
        to_div[*itr2] = nb1[*itr2];
        to_div[*itr2 + 1] = '\0';
        sub = sub_inf(to_div, nb2);
    }
    free(sub);
    return (to_div);
}

char *calc_div(char *nb1, char *nb2, char *result, int i)
{
    int itr2 = 0;
    char *temp;
    char *to_div;

    if (my_nbrcmp(nb1, nb2) < 0) {
        result[0] = '0';
        result[1] = '\0';
        return (result);
    }
    to_div = calc_first_div(nb1, nb2, &itr2);
    temp = calc_div_2(nb1, nb2, to_div, itr2);
    for (int j = 0; temp[j]; ++i, ++j)
        result[i] = temp[j];
    result[i] = '\0';
    free(temp);
    free(to_div);
    return (result);
}

int sign_detec_div(char **x, char **y)
{
    int sign = 0;

    if (*x[0] == '-' && *y[0] == '-') {
        (*x)++;
        (*y)++;
    } else if (*x[0] == '-' || *y[0] == '-') {
        *x[0] == '-' ? (*x)++ : (*y)++;
        sign++;
    }
    for (; *x[0] == '0' && (*x)[1]; (*x)++);
    for (; *y[0] == '0' && (*y)[1]; (*y)++);
    return (sign && my_nbrcmp(*x, *y) <	0 ? sign - 1 : sign);
}

char *infin_div(char *x, char *y)
{
    int sign = sign_detec_div(&x, &y);
    char *str;
    int lenx = my_strlen(x);
    int leny = my_strlen(y);
    int i = 0;

    if (my_nbrcmp(x, y) < 0) {
        if (!(str = malloc(sizeof(char) * 2)))
            return (NULL);
    } else
        if (!(str = malloc(sizeof(char) * (lenx - leny + 2 + sign))))
            return (NULL);
    sign ? str[i++] = '-' : 0;
    if (!my_strcmp(y, "0") || !calc_div(x, y, str, i)) {
        my_putstr("syntax error\n");
        free(str);
        return (NULL);
    }
    return (str);
}
