/*
** EPITECH PROJECT, 2020
** Day8
** File description:
** my_str_to_word_array
*/

#include "../include/header.h"

static int is_separator(char *separator, char c)
{
    int i = 0;

    while (separator[i] != '\0') {
        if (separator[i] == c)
            return (1);
        i++;
    }
    return (0);
}

static int size_of_word(char *str, char *separator, int index, int size)
{
    int i = 0;

    if (index < size - 1)
        while (!is_separator(separator, str[i]) && str[i] != '\0')
            i++;
    else
        while (str[i] != '\0')
            i++;
    return (i);
}

static int add_word(char **tab, int *index, int size, char **utils)
{
    int i = 0;
    int len = size_of_word(utils[0], utils[1], *index, size);

    tab[*index] = malloc(sizeof(char) * (len + 1));
    if (tab[*index] == NULL)
        return (-1);
    while (i < len) {
        tab[*index][i] = utils[0][i];
        i++;
    }
    tab[*index][i] = '\0';
    if (tab[*index][my_strlen(tab[*index]) - 1] < 32 ||
    tab[*index][my_strlen(tab[*index]) - 1] >= 127)
        tab[*index][my_strlen(tab[*index]) - 1] = '\0';
    *index += 1;
    return (len);
}

int number_of_nwords(char *str, char *separator, int max)
{
    int i = 0;
    int number = 0;

    while (str[i] != '\0') {
        if (i > 0 && !is_separator(separator, str[i]) &&
        is_separator(separator, str[i - 1]))
            number++;
        else if (i == 0 && !is_separator(separator, str[i]))
            number++;
        i++;
    }
    return (number > max ? max : number);
}

char **my_nstr_to_array(char *str, char *separator, int size)
{
    int nwords = number_of_nwords(str, separator, size);
    char **tab = malloc(sizeof(char *) * (nwords + 1));
    int index = 0;
    int ret;

    if (tab == NULL)
        return (NULL);
    tab[nwords] = NULL;
    while (*str != '\0') {
        if (is_separator(separator, *str)) {
            str += 1;
            continue;
        }
        ret = add_word(tab, &index, size, (char *[2]) {str, separator});
        if (ret == -1)
            return (NULL);
        str += ret;
    }
    return (tab);
}