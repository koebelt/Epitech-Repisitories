/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-thomas.koebel
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>


typedef struct pos {
    int x;
    int y;
} pos_t;

typedef struct path_cell {
    pos_t pos;
    struct path_cell *next;
} path_cell_t;

void add_path_cell(path_cell_t **path, pos_t pos);
int list_size(path_cell_t *path);
path_cell_t *dig_to_random_neighbor(char **maze, path_cell_t *path,
path_cell_t *neighbors);
path_cell_t *detect_neighbors(char **maze, path_cell_t *path);
void add_path_cell(path_cell_t **path, pos_t pos);
int list_size(path_cell_t *path);

#endif /* !INCLUDE_H_ */