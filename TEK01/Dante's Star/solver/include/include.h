/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** include
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
#include <string.h>
#include <time.h>

#define SOLVED if (win) return (win);

typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct path_cell {
    pos_t pos;
    struct path_cell *next;
} path_cell_t;

typedef struct path {
    path_cell_t *path;
    struct path *next;
} path_t;

char **my_str_to_tab(char const *str);
void create_path(path_t *path, pos_t pos, path_t **paths);
int list_size(path_cell_t *path);
void add_path_cell(path_cell_t **path, pos_t pos);
path_t *solve_maze(char **maze, path_t **paths, pos_t size, path_t *path);
char **read_from_file(char const *filepath);
path_t *solve_maze(char **maze, path_t **paths, pos_t size, path_t *path);
path_t *solve_loop(char **maze, pos_t size, path_t **paths);
path_cell_t *detect_neighbors(char **maze, path_cell_t *path);
void print_maze(char **maze);
pos_t maze_size(char **maze);

#endif /* !INCLUDE_H_ */