/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** convert a str into a tab
*/

#include "my.h"
#include <stdlib.h>

int count_word_len(char const *str)
{
    int	a = 0;

    while (str[a] != '\n' && str[a] != '\0')
        a++;
    return (a);
}

int how_many_words(char const *str)
{
    int	result = 0;

    for (int a = 0; str[a]; ++a) {
        if (str[a] == '\n')
            ++result;
    }
    return (result);
}

int str_to_array_loop(char const *str, int i, int j, char **tab)
{
    int	a = 0;

    while (str[i] == '\n' && str[i] != '\0')
        i++;
    tab[j] = malloc(sizeof(**tab) * (count_word_len(&str[i]) + 1));
    if (tab[j] == NULL) {
        return (-1);
    }
    while (str[i] != '\n' && str[i] != '\0') {
        tab[j][a] = str[i];
        i++;
        a++;
    }
    tab[j][a] = '\0';
	return (i);
}

char **my_str_to_word_array(char const *str)
{
    int	a = 0;
    int	b = 0;
    char **tab;

    tab = malloc(sizeof(*tab) * (how_many_words(str) + 1));
    if (tab == NULL) {
        return (NULL);
    }
    while (a < how_many_words(str)) {
        b = str_to_array_loop(str, b, a, tab);
        if (b == -1) {
            return (NULL);
        }
        a++;
    }
    tab[a] = NULL;
    return (tab);
}
