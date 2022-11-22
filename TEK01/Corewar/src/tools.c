/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tools
*/

#include "../include/header.h"

char *my_strcat(char *begin, char *end)
{
    int begin_lenght = 0;
    int end_lenght = 0;
    int i = 0;
    char *final;

    for (; begin[begin_lenght]; begin_lenght++);
    for (; end[end_lenght]; end_lenght++);
    final = malloc(sizeof(char) * ((end_lenght + begin_lenght) + 2));
    for (int j = 0; begin[j]; j++) {
        final[i] = begin[j];
        i++;
    }
    for (int j = 0; end[j]; j++) {
        final[i] = end[j];
        i++;
    }
    final[i] = '\0';
    return (final);
}

int my_tab_len(char **tab)
{
    int i = 0;

    for (i = 0; tab[i]; i++);
    return (i);
}