/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** main
*/

#include "../include/antman.h"

int main(int ac, char **av)
{
    char *spacer = " ',.";
    char *file = open_that(ac, av[1]);
    char **word_tab = my_str_to_word_array(file, spacer);
    int *index = malloc(sizeof(int) * tab_length(word_tab));

    if (error_handeling(ac, av))
        return (84);
    index = fill_indexs(word_tab, index);
    for (int i = 0, n = 0; i < tab_length(word_tab); ++i)
        if (index[i] > n) {
            my_putstr(word_tab[i]);
            my_putchar('@');
            ++n;
        }
    display(word_tab, index, file, spacer);
}

int display(char **word_tab, int *index, char *file, char *spacer)
{
    my_putchar('|');
    for (int i = 0, j = 0; i <= tab_length(word_tab); ++i) {
        for (; is_in_str(file[j], spacer) && file[j]; ++j)
            my_putchar(file[j]);
        for (; !is_in_str(file[j], spacer) && file[j]; ++j);
        if (index[i] != 0)
            my_put_nbr(index[i]);
    }
    my_putchar('\n');
}

int error_handeling(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_strcmp(av[2], "1") != 0)
        return (84);
}