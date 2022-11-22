/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** player_input
*/

#include "../include/include.h"

int is_good_line(char *line, int lines)
{
    int line_int = 0;

    if (!is_decimal(line))
        return (0);
    line_int = my_getnbr(line);
    if (line_int < 1 || line_int > lines) {
        write(1, "Error: this line is out of range\n", 33);
        return (0);
    }
    return (line_int);
}

int is_good_matches(char *matches, char **tab, int line, int limit)
{
    int matches_on_line = 0;
    int matches_int = 0;

    if (!is_decimal(matches))
        return (0);
    for (int i = 0; tab[line][i]; ++i)
        if (tab[line][i] == '|')
            ++matches_on_line;
    if ((matches_int = my_getnbr(matches)) < 1) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (0);
    } if (matches_int > matches_on_line) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (0);
    } if (matches_int > limit) {
        write(1, "Error: you cannot remove more than ", 35);
        write(1, my_int_to_str(limit), my_int_len(limit));
        write(1, " matches per turn\n", 18);
        return (0);
    }
    return (matches_int);
}

int get_matches(char **tab, int limit, int matches_line)
{
    int good_matches = 0;
    char *line = NULL;
    size_t len = 0;

    write(1, "Matches: ", 9);
    if (getline(&line, &len, stdin) == -1)
        return (-1);
    good_matches = is_good_matches(line, tab, matches_line - 1, limit);
    return (good_matches);
}