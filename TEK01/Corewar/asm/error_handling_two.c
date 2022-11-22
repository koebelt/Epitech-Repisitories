/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** error_handling_two
*/

#include "../include/header.h"

int end_with_s(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++);
    if (str[i - 2] == '.' && str[i - 1] == 's')
        return (1);
    else
        return (0);
}

void has_header(file_t *file)
{
    int error = 0;

    for (list_t *tmp = file->lines; tmp != NULL; tmp = tmp->next) {
        if (tmp->id != 100 && (!my_strcmp(tmp->ptr.line.type, ".name") ||
        !my_strcmp(tmp->ptr.line.type, ".comment")))
            error += 1;
    }
    if (error != 2)
        exit(84);
}