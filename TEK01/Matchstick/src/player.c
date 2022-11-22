/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** player
*/

#include "../include/include.h"

void rm_matches(int line, int nb_matches, char **tab)
{
    int j = my_strlen(tab[line]) - 1;

    for (; tab[line][j] == ' '; --j);
    for (int k = 0; k < nb_matches; --j, ++k)
        tab[line][j] = ' ';
    write(1, "Player removed ", 15);
    write(1, my_int_to_str(nb_matches), my_int_len(nb_matches));
    write(1, " match(es) from line ", 21);
    write(1, my_int_to_str(line + 1), my_int_len(line + 1));
    write(1, "\n", 1);
}

int is_decimal(char *line)
{
    for (int i = 0; line[i] != '\n'; ++i)
        if (line[i] < '0' || line[i] > '9') {
            write(1, "Error: invalid input (positive number expected)\n", 48);
            return (0);
        }
    return (1);
}

int get_good_input(char **tab, int limit, int lines)
{
    int good_line = 0;
    int good_matches = 0;
    char *line = NULL;
    size_t len = 0;

    write(1, "\nYour turn:\n", 12);
    while (!good_matches) {
        good_line = 0;
        while (!good_line) {
            line = NULL;
            len = 0;
            write(1, "Line: ", 6);
            IS_CTRL_D
            good_line = is_good_line(line, lines);
        }
        good_matches = get_matches(tab, limit, good_line);
        if (good_matches == -1)
            return (-1);
    }
    rm_matches(good_line - 1, good_matches, tab);
}