/*
** EPITECH PROJECT, 2021
** stumper_2
** File description:
** my_str_to_word_array.c
*/

#include "../include/include.h"

char **read_from_file(char const *filepath)
{
    struct stat var;
    int file_descriptor = open(filepath, O_RDONLY);
    int ret = 0;
    char *buffer = NULL;
    char **tab;

    if (file_descriptor == -1)
        exit (84);
    stat(filepath, &var);
    buffer = malloc(sizeof(char) * (var.st_size + 4));
    while ((ret = read(file_descriptor, buffer, var.st_size)) > 0 &&
    buffer[0] != '\0')
        buffer[ret] = '\0';
    tab = my_str_to_tab(buffer);
    free(buffer);
    return (tab);
}

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
        if (str[a] == '\n' || str[a] == '\0')
            ++result;
    }
    return (result);
}

int str_to_array_loop(char const *str, int i, int j, char **tab)
{
    int	a = 0;

    while ((str[i] == '\n') && str[i] != '\0')
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

char **my_str_to_tab(char const *str)
{
    int	a = 0;
    int	b = 0;
    char **tab;

    tab = malloc(sizeof(*tab) * (how_many_words(str) + 2));
    if (tab == NULL) {
        return (NULL);
    }
    while (a <= how_many_words(str)) {
        b = str_to_array_loop(str, b, a, tab);
        if (b == -1) {
            return (NULL);
        }
        a++;
    }
    tab[a] = NULL;
    return (tab);
}
