/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** path
*/

#include "../include/include.h"

void my_rev_list(path_cell_t **begin)
{
    path_cell_t *prev = NULL;
    path_cell_t *current = *begin;
    path_cell_t *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
}

path_cell_t *duplicate_prev_path(path_cell_t *current)
{
    path_cell_t *new_path = NULL;
    path_cell_t *tmp = NULL;

    tmp = current;
    while (tmp != NULL) {
        add_path_cell(&new_path, tmp->pos);
        tmp = tmp->next;
    }
    my_rev_list(&new_path);
    return (new_path);
}

void create_path(path_t *path, pos_t pos, path_t **paths)
{
    path_t *element;

    element = malloc(sizeof(*element));
    element->path = NULL;
    if (path != NULL)
        element->path = duplicate_prev_path(path->path);
    add_path_cell(&element->path, pos);
    element->next = *paths;
    *paths = element;
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

