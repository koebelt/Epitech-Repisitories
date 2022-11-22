/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** fnc to find a square
*/

#include "include/my.h"

int check_fit(char **tab, t_map map_data, t_square max)
{
    int i = 0;
    int j = 0;

    for (; i < max.size && i + max.x <= map_data.width; ++i) {
        for (j = 0; j < max.size && j + max.y <= map_data.height; ++j) {
            if (tab[i + max.x][j + max.y] != '.')
                return (0);
        }
    }
    if (i == max.size && j == max.size)
        return (1);
    else
        return (0);
}

void try_max(char **tab, t_map *map_data, int x, int y)
{
    t_square max = {x, y, 1};

    while (check_fit(tab, *map_data, max))
        max.size++;
    max.size--;
    if (max.size > map_data->max)
    {
        map_data->max = max.size;
        map_data->x = x;
        map_data->y = y;
    }
}

char **find(char **tab)
{
    t_map map_data = {my_tab_size(tab), my_strlen(tab[1]), 0, 0, 0};

    for (int i = 0; i + map_data.max <= map_data.width; ++i)
        for (int j = 0; j + map_data.max <= map_data.height; ++j)
            try_max(tab, &map_data, i, j);
    for (int i = 0; i < map_data.max; ++i) {
        for (int j = 0; j < map_data.max; ++j)
            tab[i + map_data.x][j + map_data.y] = 'x';
    }
    return (tab);
}
