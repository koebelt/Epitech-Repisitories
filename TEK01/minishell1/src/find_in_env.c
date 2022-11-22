/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-thomas.koebel
** File description:
** find_in env
*/

#include "../include/include.h"

int is_path(char *str)
{
    if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T' && str[3] == 'H'
    && str[4] == '=')
        return (1);
    return (0);
}

char **init_path(char **env)
{
    char **path;

    for (int i = 0; env[i]; ++i) {
        if(is_path(env[i])) {
            env[i] += 5;
            path = my_str_to_word_array(env[i], ":");
        }
    }
    return (path);
}

int is_home(char *str)
{
    if (str[0] == 'H' && str[1] == 'O' && str[2] == 'M' && str[3] == 'E'
    && str[4] == '=')
        return (1);
    return (0);
}

char *find_home(char **env)
{
    char *home;
    int j = 0;

    for (int i = 0; env[i]; ++i) {
        if(is_home(env[i])) {
            env[i] += 5;
            home = malloc (sizeof(char) * my_strlen(env[i]));
            for (j = 0; env[i][j]; ++j)
                home[j] = env[i][j];
            home[j] = '\0';
        }
    }
    return (home);
}
