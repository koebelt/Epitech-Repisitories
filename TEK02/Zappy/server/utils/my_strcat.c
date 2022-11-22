/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, char *src)
{
    if (!dest)
        return (strdup(src));
    dest = realloc(dest, sizeof(char) * (strlen(dest) + strlen(src) + 1));
    strcat(dest, src);
    return (dest);
}