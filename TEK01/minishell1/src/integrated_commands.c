/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-thomas.koebel
** File description:
** integrated_commands
*/

#include "../include/include.h"

int my_cd(char **command, env_t *env)
{
    int ret = 0;

    if (!command[1] || my_strcmp(command[1], "~") == 0)
        ret = chdir(env->home);
    else if (command[1] != NULL)
        ret = chdir(command[1]);
    if (ret == -1) {
        perror(command[1]);
    }
    return (ret == -1 ? 1 : 0);
}

int intergrated_cmd(char **path, char **command, env_t *env)
{
    if (my_strcmp(command[0], "cd") == 0)
        return (my_cd(command, env));
    if (my_strcmp(command[0], "exit") == 0) {
        env->ret = command[1] != NULL ? my_getnbr(command[1]) : 0;
        return (command[1] != NULL ? my_getnbr(command[1]) : 0);
    }
    return (-1);
}