/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** board
*/

#include "../include/include.h"

int find_tab_size(int lines)
{
    int size = 1;

    for (int i = 1; i < lines; ++i, size += 2);
    return (size);
}

char **create_board(int lines)
{
    char **tab = malloc(sizeof(char *) * (lines));
    int tab_size = find_tab_size (lines);
    int i = 0;
    int j = 0;
    int size = 1;

    for (i = 0; i < lines; ++i)
        tab[i] = malloc(sizeof(char) * (tab_size + 1));
    for (i = 0; i < lines; ++i, size += 2) {
        for (j = 0; j < ((tab_size - size) / 2); ++j)
            tab[i][j] = ' ';
        for (int k = 0; k < size; ++j, ++k)
            tab[i][j] = '|';
        for (int k = 0; k < ((tab_size - size) / 2); ++j, ++k)
            tab[i][j] = ' ';
        tab[i][j] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}

void print_game(char **tab, int size)
{
    for (int i = 0; i < size + 2; ++i)
        write (1, "*", 1);
    write(1, "\n", 1);
    for (int i = 0; tab[i]; ++i) {
        write(1, "*", 1);
        for (int j = 0; tab[i][j]; ++j)
            write(1, &tab[i][j], 1);
        write(1, "*\n", 2);
    }
    for (int i = 0; i < size + 2; ++i)
        write (1, "*", 1);
    write(1, "\n", 1);
}
