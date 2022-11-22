/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** path
*/

#include "../include/include.h"

path_cell_t *dig_to_random_neighbor(char **maze, path_cell_t *path,
path_cell_t *neighbors)
{
    int random = 0;

    if (neighbors == NULL) {
        path = path->next;
        return (path);
    }
    random = rand() % list_size(neighbors);
    for (int i = 0; i < random; ++i, neighbors = neighbors->next);
    path->pos.x > neighbors->pos.x ? maze[path->pos.y][path->pos.x - 1] = '*':
    0;
    path->pos.x < neighbors->pos.x ? maze[path->pos.y][path->pos.x + 1] = '*':
    0;
    path->pos.y > neighbors->pos.y ? maze[path->pos.y - 1][path->pos.x] = '*':
    0;
    path->pos.y < neighbors->pos.y ? maze[path->pos.y + 1][path->pos.x] = '*':
    0;
    maze[neighbors->pos.y][neighbors->pos.x] = '*';
    add_path_cell(&path, neighbors->pos);
    return (path);
}

path_cell_t *detect_neighbors(char **maze, path_cell_t *path)
{
    path_cell_t *neighbors = NULL;

    if (maze[path->pos.y][path->pos.x + 1] &&
    maze[path->pos.y][path->pos.x + 2] == 'X')
        add_path_cell(&neighbors, (pos_t){path->pos.x + 2, path->pos.y});
    if (path->pos.x - 2 >= 0 &&
    maze[path->pos.y][path->pos.x - 2] == 'X')
        add_path_cell(&neighbors, (pos_t){path->pos.x - 2, path->pos.y});
    if (maze[path->pos.y + 1] && maze[path->pos.y + 2] &&
    maze[path->pos.y + 2][path->pos.x] == 'X')
        add_path_cell(&neighbors, (pos_t){path->pos.x, path->pos.y + 2});
    if (path->pos.y - 2 >= 0 &&
    maze[path->pos.y - 2][path->pos.x] == 'X')
        add_path_cell(&neighbors, (pos_t){path->pos.x, path->pos.y - 2});
    return (neighbors);
}

void add_path_cell(path_cell_t **path, pos_t pos)
{
    path_cell_t *element;

    element = malloc(sizeof(*element));
    element->pos = pos;
    element->next = *path;
    *path = element;
}

int list_size(path_cell_t *path)
{
    path_cell_t *tmp = path;
    int size = 0;

    while (tmp != NULL) {
        ++size;
        tmp = tmp->next;
    }
    return (size);
}

