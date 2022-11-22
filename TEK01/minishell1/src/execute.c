/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-thomas.koebel
** File description:
** execute
*/

#include "../include/include.h"

int execute_command(char **path, char **command, env_t *env)
{
    int ret = -1;
    char *path_corrected = NULL;

    if (command[0][0] == '.' || command[0][0] == '/')
        return (execve(command[0], command, env->env));
    for (int i = 0; path[i] && ret == -1; ++i) {
        path_corrected = my_strcat(path[i], my_strcat("/", command[0]));
        ret = execve(path_corrected, command, env->env);
        free(path_corrected);
    }
    return (ret);
}

int execute(char **path, char **command, env_t *env)
{
    pid_t pid;
    int wstatus;
    int ret = 0;

    if ((ret = intergrated_cmd(path, command, env)) != -1)
        return (ret);
    ret = 0;
    if ((pid = fork()) == -1)
        perror("fork");
    else if (pid == 0 && (ret = execute_command(path, command, env)) == -1) {
        perror(command[0]);
    } else
        while (waitpid(pid, &wstatus, 0) != -1 && !WIFEXITED(wstatus)) {
            if (WIFSIGNALED(wstatus) && WTERMSIG(wstatus) == SIGSEGV) {
                my_printf("Segmentation fault%s\n", WCOREDUMP(wstatus) ?
                " (core dumped)" : "");
                ret = 84;
            } else if (WIFSIGNALED(wstatus) && WTERMSIG(wstatus) == SIGFPE) {
                my_printf("Floating exception%s\n",
                WCOREDUMP(wstatus) ? " (core dumped)" : "");
                ret = 84;
            }
        }
    return (ret);
}

int command(char **path, env_t *env) {
    char *line = NULL;
    char **command = NULL;
    long unsigned int len = 0;
    int ret = 0;

    ret = getline(&line, &len, stdin);
    if (ret == -1) {
        env->ret = -1;
        return (ret);
    }
    if (line[0] != '\n' && line[0] != '\0') {
        while (line[0] == ' ' || line[0] == '\t')
            ++line;
        command = my_str_to_word_array(line, " \n\t");
        ret = execute(path, command, env);
    }
    return (ret);
}