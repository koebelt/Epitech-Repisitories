/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** load_map.c
*/

#include "include.h"

char **read_file(char const *path)
{
    char **tab;
    struct stat var;
    int fd = open(path, O_RDONLY);
    int ret;
    char *buffer;

    if (fd == -1)
        return (NULL);
    stat(path, &var);
    buffer = malloc(sizeof(char) * (var.st_size));
    ret = read(fd, buffer, var.st_size);
    buffer[ret] = '\0';
    close(fd);
    tab = my_str_to_word_array(buffer);
    return (tab);
}

void load_map(char *path, window_obj_t *window)
{
    window->game.obstacles.tab = read_file(path);
    for (int i = 0; window->game.obstacles.tab[i]; ++i)
        for (int j = 0; window->game.obstacles.tab[i][j]; ++j) {
            window->game.obstacles.tab[i][j] == '0' ?
            load_obs0(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '1' ?
            load_obs1(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '2' ?
            load_obs2(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '3' ?
            load_obs3(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '4' ?
            load_obs4(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '5' ?
            load_obs5(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '6' ?
            load_obs6(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '7' ?
            load_obs7(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '8' ?
            load_obs8(&window->game.obstacles, j, i) : 0;
            window->game.obstacles.tab[i][j] == '9' ?
            load_obs9(&window->game.obstacles, j, i, window->clock) : 0;
    }
}

void init_obstacles(obstacles_t *obstacles)
{
    obstacles->cell_size = 48 * 4;
    for (int i = 0; i < 10; ++i)
        obstacles->nbr_of_occurences[i] = 0;
}
