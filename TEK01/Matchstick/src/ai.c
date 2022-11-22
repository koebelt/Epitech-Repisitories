/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** ai
*/

#include "../include/include.h"

void rm_ai_move(char **tab, int line, int nb)
{
    int j = my_strlen(tab[line]) - 1;

    for (; tab[line][j] == ' '; --j);
    for (int k = 0; k < nb; --j, ++k)
        tab[line][j] = ' ';
    write(1, "AI removed ", 11);
    write(1, my_int_to_str(nb), my_int_len(nb));
    write(1, " match(es) from line ", 21);
    write(1, my_int_to_str(line + 1), my_int_len(line + 1));
    write(1, "\n", 1);
}

void do_bad_move(char **tab, int limit, int matches)
{
    int line = 0;
    int emergency_nb = 1;

    for (int i = 1; i <= limit; ++i)
        if ((matches - i) % (limit + 1) != 1) {
            line = is_possible_move(tab, &i);
            rm_ai_move(tab, line, i);
            return;
        }
    line = is_possible_move(tab, &emergency_nb);
    rm_ai_move(tab, line, emergency_nb);
}

void do_the_best_move(char **tab, int limit, int matches)
{
    int line = 0;
    int emergency_nb = 1;

    for (int i = 1; i <= limit; ++i)
        if ((matches - i) % (limit + 1) == 1) {
            line = is_possible_move(tab, &i);
            rm_ai_move(tab, line, i);
            return;
        }
    line = is_possible_move(tab, &emergency_nb);
    rm_ai_move(tab, line, emergency_nb);
}

void ai_play(char **tab, int limit)
{
    int matches = count_matches(tab);

    write(1, "\nAI's turn...\n", 14);
    if (matches % (limit + 1) == 1)
        do_bad_move(tab, limit, matches);
    else {
        do_the_best_move(tab, limit, matches);
    }
}