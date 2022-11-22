/*
** EPITECH PROJECT, 2020
** add
** File description:
** adding part for the add_inf prog
*/

#include <stdlib.h>
#include "./include/my.h"

void adding(char *bigger, char *shorter, char *result, int retenue)
{
    int i = 0;
    
    for (int add = 0; bigger[i] != '\0'; ++i, add = 0) {
        if (i >= my_strlen(shorter))
            add = bigger[i] - 48;
        else
            add = bigger[i] + shorter[i] - 48 - 48;
        if (add + retenue > 9) {
            result[i] = add - 10 + retenue + 48;
            retenue = 1;
        } else {
            result[i] = add + retenue + 48;
            retenue = 0;
        }
    }
    if (retenue != 0) {
        result[i] = retenue + 48;
        result[i + 1] = '\0';
    } else
        result[i] = '\0';
    if (result[0] == '0' && result [1] == '\0')
        my_putstr("0");
    else
        my_putstr0(my_revstr(result));
}

char *infin_add(char *g, char *d)
{
    my_revstr(g);
    my_revstr(d);
    
    char *bigger = my_str_is_bigger(g, d);
    char *shorter = my_strislower(g, d);
    char *result;
    int retenue = 0;

    result = malloc(sizeof(*result) * my_strlen(bigger) + 2);

    adding(bigger, shorter, result, retenue);
}

