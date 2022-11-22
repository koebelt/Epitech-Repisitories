/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-thomas.koebel
** File description:
** main.c
*/

#include "../include/include.h"

int minishell(env_t *env, int ret)
{
    if (env->ret != -2)
        return(env->ret);
    display_prompt(ret);
    ret = command(env->path, env);
    if (env->ret != -2)
        return(env->ret);
    return (minishell(env, ret));
}

int main(int ac, char **av, char **env)
{
    env_t env_struct;

    env_struct.path = init_path(env);
    env_struct.env = env;
    env_struct.home = find_home(env);
    env_struct.pid = getpid();
    env_struct.ret = -2;
    return (minishell(&env_struct, 0));
}
