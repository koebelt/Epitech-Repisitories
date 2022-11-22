/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-thomas.koebel
** File description:
** my_str_to_word_array
*/

#include "../include/giantman.h"

int count_word_len(char const *str, char *separators)
{
    int	a = 0;

    while (!is_in_str(str[a], separators) && str[a] != '\0')
        a++;
    return (a);
}

int how_many_words(char const *str, char *separators)
{
    int	result = 0;

    for (int a = 0; str[a]; ++a) {
        if (is_in_str(str[a], separators) || str[a] == '\0')
            ++result;
    }
    return (result);
}

int str_to_array_loop(char const *str, int i, int j, char **tab, char *separators)
{
    int	a = 0;

    while (is_in_str(str[i], separators) && str[i] != '\0')
        i++;
    tab[j] = malloc(sizeof(**tab) * (count_word_len(&str[i], separators) + 1));
    if (tab[j] == NULL) {
        return (-1);
    }
    while (!is_in_str(str[i], separators) && str[i] != '\0') {
        tab[j][a] = str[i];
        i++;
        a++;
    }
    tab[j][a] = '\0';
    return (i);
}

char **my_str_to_word_array(char const *str, char *separators)
{
    int	a = 0;
    int	b = 0;
    char **tab;

    tab = malloc(sizeof(*tab) * (how_many_words(str, separators) + 2));
    if (tab == NULL) {
        return (NULL);
    }
    while (a <= how_many_words(str, separators)) {
        b = str_to_array_loop(str, b, a, tab, separators);
        if (b == -1) {
            return (NULL);
        }
        a++;
    }
    tab[a] = NULL;
    return (tab);
}
