/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thibaut.ruscher
** File description:
** load_file
*/

#include "../include/header.h"

static int count_lines(char *filename)
{
    FILE *stream;
    int count = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    stream = fopen(filename, "r");
    if (stream == NULL)
        return (84);
    while ((nread = getline(&line, &len, stream)) != -1)
        count++;
    fclose(stream);
    return (count);
}

char **load_fcontent(char *filename)
{
    FILE *stream;
    int nlines = count_lines(filename);
    char **tab = NULL;
    char *line = NULL;
    size_t len = 0;
    int i = 0;
    ssize_t nread;

    tab = malloc(sizeof(char *) * (nlines + 1));
    tab[nlines] = NULL;
    stream = fopen(filename, "r");
    if (stream == NULL)
        return (NULL);
    while ((nread = getline(&line, &len, stream)) != -1) {
        tab[i] = malloc(sizeof(char) * (nread + 1));
        tab[i] = my_strdup(line);
        i++;
    }
    fclose(stream);
    return (tab);
}