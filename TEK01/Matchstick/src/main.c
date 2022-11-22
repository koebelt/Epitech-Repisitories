/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** main
*/

#include "../include/include.h"

int lost(char **tab)
{
    int is_lost = 1;

    for (int i = 0; tab[i]; ++i)
        for (int j = 0; tab[i][j]; ++j)
            tab[i][j] == '|' ? is_lost = 0 : 0;
    return (is_lost);
}

int game_loop(char **tab, int lines, int limit, int size)
{
    print_game(tab, size);
    if (lost(tab))
        return (1);
    if (get_good_input(tab, limit, lines) == -1)
        return (0);
    print_game(tab, size);
    if (lost(tab))
        return (2);
    ai_play(tab, limit);
    return (game_loop(tab, lines, limit, size));
}

int main(int ac, char **av)
{
    int lines = my_getnbr(av[1]);
    int limit = my_getnbr(av[2]);
    char **tab = create_board(lines);
    int size = find_tab_size (lines);
    int ret = 0;

    if (ac != 3)
        return (84);
    ret = game_loop(tab, lines, limit, size);
    if (ret == 1) {
        write(1, "I lost... snif... but I'll get you next time!!\n", 48);
        return (1);
    }
    if (ret == 2) {
        write(1, "You lost, too bad...\n", 21);
        return (2);
    }
    return (0);
}