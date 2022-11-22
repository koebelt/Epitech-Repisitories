/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/include.h"

void print_solved(char **maze, path_cell_t **path)
{
    path_cell_t *tmp = *path;

    while (tmp != NULL) {
        maze[tmp->pos.y][tmp->pos.x] = 'o';
        tmp = tmp->next;
    }
    for (int i = 0; maze[i]; ++i)
        for (int j = 0; maze[i][j] != '\0'; j++)
            maze[i][j] == 'v' ? maze[i][j] = '*' : 0;
    print_maze(maze);
}

int main(int ac, char **av)
{
    char **maze = NULL;
    path_t *paths = NULL;
    pos_t size = {.x = 0, .y = 0};
    path_t *solved = NULL;

    maze = read_from_file(av[1]);
    size = maze_size(maze);
    maze[0][0] = 'v';
    create_path(NULL, (pos_t){0, 0}, &paths);
    solved = solve_loop(maze, size, &paths);
    print_solved(maze, &solved->path);
    return (0);
}