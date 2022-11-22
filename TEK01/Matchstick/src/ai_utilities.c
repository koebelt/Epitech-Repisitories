/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** ai_utilities
*/

#include "../include/include.h"

int count_on_line(char **tab, int line)
{
    int count = 0;

    for (int i = 0; tab[line][i]; ++i)
        tab[line][i] == '|' ? ++count : 0;
    return (count);
}

int is_possible_move(char **tab, int *nb)
{
    for (int i = 0; tab[i]; ++i)
        if (count_on_line(tab, i) >= *nb)
            return (i);
    *nb = 1;
    return (is_possible_move(tab, nb));
}

int count_matches(char **tab)
{
    int matches_count = 0;

    for (int i = 0; tab[i]; ++i)
        for (int j = 0; tab[i][j]; ++j)
            tab[i][j] == '|' ? matches_count++ : 0;
    return (matches_count);
}
