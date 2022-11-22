/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-thomas.koebel
** File description:
** read_map
*/

#include "../include/include.h"

char **read_map(char const *path)
{
    char **tab;
    struct stat var;
    int fd = open(path, O_RDONLY);
    int ret;
    char *buffer;

    if (fd == -1)
        return (NULL);
    stat(path, &var);
    buffer = malloc(sizeof(char) * (var.st_size));
    ret = read(fd, buffer, var.st_size);
    buffer[ret] = '\0';
    tab = my_str_to_word_array(buffer, "\n");
    return (tab);
}