/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-thomas.koebel
** File description:
** include.h
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <malloc.h>
#include <sys/sysmacros.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/wait.h>
#include <signal.h>

typedef struct env {
    char **path;
    char **env;
    char **new_env;
    char *home;
    int pid;
    int ret;
} env_t;

char **my_str_to_word_array(char const *, char *);
char **my_command_to_tab(char const *);
char *my_strcat(char *, char *);
int my_strcmp(char const *, char const *);
int my_strlen(char const *);
int	my_getnbr(const char *str);
int command(char **path, env_t *env);
int is_path(char *str);
char **init_path(char **env);
int is_home(char *str);
char *find_home(char **env);
int intergrated_cmd(char **path, char **command, env_t *env);

#endif /* INCLUDE_H_ */
