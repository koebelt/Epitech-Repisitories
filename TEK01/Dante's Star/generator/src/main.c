/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "../include/include.h"

void dig_perfect_maze(char **maze)
{
    path_cell_t *path = NULL;
    path_cell_t *neighbors = NULL;

    add_path_cell(&path, (pos_t){0, 0});
    maze[0][0] = '*';
    while (path != NULL) {
        neighbors = detect_neighbors(maze, path);
        path = dig_to_random_neighbor(maze, path, neighbors);
    }
}

void print_maze(char **maze)
{
    for (int i = 0; maze[i]; ++i)
        printf("%s%s", maze[i], maze[i + 1] ? "\n" : "");
}

char **create_filled_maze(int size_x, int size_y)
{
    char **maze = malloc(sizeof(char *) * (size_y + 1));
    int k = 0;
    int j = 0;

    for (int i = 0; i < size_y; ++i)
        maze[i] = malloc(sizeof(char) * (size_x + 1));
    for (k = 0; k < size_y; ++k) {
        for (j = 0; j < size_x; ++j)
            maze[k][j] = 'X';
        maze[k][j] = '\0';
    }
    maze[k] = NULL;
    return (maze);
}

void dig_imperfect_maze(char **maze, int size_x, int size_y)
{
    int size_moy = (size_x + size_y) / 2;
    int to_remove = size_moy;
    int x = 0;
    int y = 0;

    for (int i = 0; i < to_remove; ++i) {
        x = rand() % size_x;
        y = rand() % size_y;
        if (maze[y][x] == 'X')
            maze[y][x] = '*';
        else
            --i;
    }
}

int main(int ac, char **av)
{
    int size_x = atoi(av[1]);
    int size_y = atoi(av[2]);
    char **maze = create_filled_maze(size_x, size_y);

    srand(time(NULL));
    dig_perfect_maze(maze);
    if (size_x % 2 == 0 && size_y % 2 == 0) {
        maze[size_y - 1][size_x - 1] = '*';
        maze[size_y - 1][size_x - 2] = '*';
    } else if (size_x % 2 == 0 || size_y % 2 == 0)
        maze[size_y - 1][size_x - 1] = '*';
    if (ac == 3)
        dig_imperfect_maze(maze, size_x, size_y);
    print_maze(maze);
}