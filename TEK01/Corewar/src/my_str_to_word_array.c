/*
** EPITECH PROJECT, 2020
** Day8
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

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

static int size_of_word(char *str, char *separator)
{
    int i = 0;

    while (!is_separator(separator, str[i]) && str[i] != '\0')
        i++;
    return (i);
}

static int add_word(char ***tab, int *index, char *str, char *separator)
{
    int i = 0;
    int len = size_of_word(str, separator);

    (*tab)[*index] = malloc(sizeof(char) * (len + 1));
    if ((*tab)[*index] == NULL)
        return (-1);
    while (i < len) {
        (*tab)[*index][i] = str[i];
        i++;
    }
    (*tab)[*index][i] = '\0';
    *index += 1;
    return (len);
}

int number_of_words(char *str, char *separator)
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
    return (number);
}

char **my_str_to_word_array(char *str, char *separator)
{
    int nwords = number_of_words(str, separator);
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
        ret = add_word(&tab, &index, str, separator);
        if (ret == -1)
            return (NULL);
        str += ret;
    }
    return (tab);
}