/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-thomas.koebel
** File description:
** prompt
*/

#include "../include/include.h"

char *reduce_path(char *str)
{
    int i = my_strlen(str);
    int j = my_strlen(str);
    int k = 0;
    char *new;

    while (--i >= 0)
        if (str && str[i] == '/' && ++k == 2 && !(k = 0))
            break;
    if (!str || !(new = malloc(sizeof(char) * (j - i))))
        return (NULL);
    while (str[++i])
        new[k++] = str[i];
    new[k] = 0;
    return (new);
}

void display_prompt(int ret)
{
    char cwd[256];
    char *reduced_cwd;
    int n = 0;

    getcwd(cwd, sizeof(cwd));
    for (int i = 0; cwd[i]; ++i)
        cwd[i] == '/' ? ++n : 0;
    if (n > 2) {
        reduced_cwd = reduce_path(cwd);
        my_printf("\033[;32m[~/.../%s]\033[0m %s> ", reduced_cwd,
        (ret != 0 ? "\033[;31m$\033[0m" : "$"));
    } else
        my_printf("\033[;32m[~%s]\033[0m %s> ", cwd,
        (ret != 0 ? "\033[;31m$\033[0m" : "$"));
}