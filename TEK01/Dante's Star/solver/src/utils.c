/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** utils
*/

#include "../include/include.h"

pos_t maze_size(char **maze)
{
    pos_t maze_size = {.x = 0, .y = 0};

    for (int i = 0; maze[i]; i++, maze_size.y++);
    for (int i = 0; maze[0][i]; i++, maze_size.x++);
    return (maze_size);
}

void print_maze(char **maze)
{
    for (int i = 0; maze[i]; ++i)
        printf("%s%s", maze[i], maze[i + 1] ? "\n" : "");
}

path_cell_t *detect_neighbors(char **maze, path_cell_t *path)
{
    path_cell_t *neighbors = NULL;

    if (maze[path->pos.y][path->pos.x + 1] &&
    maze[path->pos.y][path->pos.x + 1] == '*')
        add_path_cell(&neighbors, (pos_t){path->pos.x + 1, path->pos.y});
    if (path->pos.x - 1 >= 0 &&
    maze[path->pos.y][path->pos.x - 1] == '*')
        add_path_cell(&neighbors, (pos_t){path->pos.x - 1, path->pos.y});
    if (maze[path->pos.y + 1] && maze[path->pos.y + 1] &&
    maze[path->pos.y + 1][path->pos.x] == '*')
        add_path_cell(&neighbors, (pos_t){path->pos.x, path->pos.y + 1});
    if (path->pos.y - 1 >= 0 &&
    maze[path->pos.y - 1][path->pos.x] == '*')
        add_path_cell(&neighbors, (pos_t){path->pos.x, path->pos.y - 1});
    return (neighbors);
}

path_t *solve_loop(char **maze, pos_t size, path_t **paths)
{
    path_t *win = NULL;
    path_t *tmp = NULL;

    while (!win) {
        tmp = *paths;
        while (tmp != NULL) {
            win = solve_maze(maze, paths, size, tmp);
            SOLVED
            tmp = tmp->next;
        }
    }
    return (win);
}

path_t *solve_maze(char **maze, path_t **paths, pos_t size, path_t *path)
{
    path_cell_t *neighbors = detect_neighbors(maze, path->path);
    path_t *current = path;

    if (current->path->pos.y == size.y - 1 &&
    current->path->pos.x == size.x - 1)
        return (current);
    else if(list_size(neighbors) == 0);
    else {
        while (neighbors->next != NULL) {
            maze[neighbors->pos.y][neighbors->pos.x] = 'v';
            create_path(current, neighbors->pos, paths);
            neighbors = neighbors->next;
        }
        maze[neighbors->pos.y][neighbors->pos.x] = 'v';
        add_path_cell(&current->path, neighbors->pos);
    }
    return (NULL);
}