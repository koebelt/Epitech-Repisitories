/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** str management
*/

#include <stdlib.h>
#include "include/my.h"

char *small_strdup(char *str, int a, int b)
{
    char *small = malloc(sizeof(char) * ((b - a) + 2));
    int i = 0;

    if (small == NULL)
        return (NULL);
    for ( ; i + a <= b ; ++i)
        small[i] = str[i + a];
    small[i] = '\0';
    return (small);
}

char *insert_result(char *str, char *result, int a, int b)
{
    int len = my_strlen(str) + my_strlen(result) - ((b - a) + 1);
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;

    if (!new)
        return (NULL);
    ++b;
    for ( ; i < a ; ++i)
        new[i] = str[i];
    for (int j = 0 ; result[j] ; ++j, ++i)
        new[i] = result[j];
    for ( ; str[b] ; ++b, ++i)
        new[i] = str[b];
    new[i] = '\0';
    free(str);
    free(result);
    return (new);
}

char *supr_space(char *str)
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));
    int a = 0;

    if (!str2)
        return (NULL);
    for (int i = 0; i <= my_strlen(str); i += 1) {
        if (str[i] != ' ') {
            str2[a] = str[i];
            a += 1;
        }
    }
    free(str);
    return (str2);
}

char *delete_exess_sign(char *str)
{
    int j = 0;
    int count = 0;
    int sign = -1;

    for (int i = 0; str[i]; ++i) {
        for (j = i; str[j] == '-' || str[j] == '+'; ++j) {
            count = str[j] == '-' ? count + 1 : count;
            sign = str[j] == '+' ? 1 : sign;
            str[j] = ' ';
        }
        if (count % 2 != 0 && count != 0)
            str[i] = '-';
        else if (((count % 2 == 0 && count != 0) || sign == 1) && (i - 1) >= 0)
            str[i] = (((str[i - 1] < 58) && (str[i - 1] > 47))
                || (str[i - 1] == ')')) ? '+' : ' ';
        count = 0;
        sign = -1;
        str = supr_space(str);
    }
    return (str);
}

char *str_format(char *str, char *operators)
{
    char *true_ope = "()+-*/%";
    int itr = 0;

    for (int i = 0; str[i]; ++i)
        for (int j = 0; operators[j]; ++j)
            str[i] = str[i] == operators[j] ? true_ope[j] : str[i];
    str = delete_exess_sign(str);
    return (supr_space(str));
}
