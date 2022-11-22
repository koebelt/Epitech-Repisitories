/*
** EPITECH PROJECT, 2020
** sub
** File description:
** sub part for the add_inf prog
*/

#include <stdlib.h>
#include "./include/my.h"

char *verif_bigger(char *neg, char *pos)
{
    for (int i = 0; neg[i] != '\0'; ++i) {
        if (neg[i] > pos[i])
            return (neg);
        else if (pos[i] > neg[i])
            return (pos);
        else
            return("0");
    }
}

char *reverse(char *str, char *neg)
{
    if (str == neg)
        return(str);
    else
        return(my_revstr(str));
}

void subbing(char *larger, char *shorter, char *neg)
{
    int i = 0;
    char *result = malloc(sizeof(*result) * sizeof(larger) + 2);
    int sub = 0;

    larger = reverse(larger, neg);
    shorter = reverse(shorter, neg);
    my_revstr(neg);

    for (int retenue = 0; larger[i] != '\0'; ++i, sub = 0) {
        if (i >= my_strlen(shorter))
            sub = (int)(larger[i] - 48) - retenue;
        else
            sub = (int)(larger[i] - 48) - ((int)(shorter[i] - 48) + retenue);
        if (sub < 0) {
            result[i] = (sub + 10) + 48;
            retenue = 1;
        } else {
            result[i] = sub + 48;
            retenue = 0;
        }
    }
    if (larger == neg) {
        result[i] = '-';
        result[i + 1] = '\0';
    } else
        result[i] = '\0';
    if (result[0] == '0' && result [1] == '\0')
        my_putstr("0");
    else
        my_putstr0(my_revstr(result));
}

char *infin_sub(char *g, char *d)
{
    int len_neg = 0;
    int len_pos = 0;
    char *neg;
    char *pos;
    char *larger;
    char *shorter;

    if (g[0] == '-') {
        g = g + 1;
        neg = g;
        pos = d;
    } else {
        d = d + 1;
        neg = d;
        pos = g;
    }
    while (neg[0] == '0')
        neg = (neg + 1);
    while (pos[0] == '0')
        pos = (pos + 1);
    len_neg = my_strlen(neg);
    len_pos = my_strlen(pos);
    if (len_neg > len_pos) {
        larger = neg;
    }
    else if (len_pos > len_neg) {
        larger = pos;
    }
    else
        larger = verif_bigger(neg, pos);
    if(larger == neg)
        shorter = pos;
    else
        shorter = neg;
    
    subbing(larger, shorter, neg);
}
