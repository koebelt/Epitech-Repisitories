/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** indexs
*/

#include "../include/antman.h"

int already_got(char **tab, char *word, int i, int *index)
{
    if (i <= 0)
        return (0);
    for (int j = 0; j < i; ++j) {
        if (my_strcmp(tab[j], word) == 0)
            return (index[j]);
    }
    
    return (0);
}

int *fill_indexs(char **tab, int *index)
{
    int n = 0;

    for (int i = 0; tab[i]; ++i) {
        int buf = already_got(tab, tab[i], i, index);
        if (buf)
            index[i] = buf;
        else
            index[i] = ++n;
    }
    return (index);
}