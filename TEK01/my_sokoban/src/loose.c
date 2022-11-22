/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-thomas.koebel
** File description:
** loose
*/

#include "../include/include.h"

int is_win(char **map, char **backup_map)
{
    int win = 1;

    for (int i = 0; map[i]; ++i)
        for (int j = 0; map[i][j]; ++j)
            backup_map[i][j] == 'O' && map[i][j] != 'X' ? win = 0 : 0;
    return (win);
}

int check_stucked(int i, int j, char **map)
{
    if (((map[i - 1][j] == '#' || map[i - 1][j] == 'X') ||
    (map[i + 1][j] == '#' || map[i + 1][j] == 'X')) &&
    ((map[i][j - 1] == '#' || map[i][j - 1] == 'X') ||
    (map[i][j + 1] == '#' || map[i][j + 1] == 'X')))
        return (1);
    return (0);
}

int count_x(char **backup_map)
{
    int count = 0;

    for (int i = 0; backup_map[i]; ++i)
        for (int j = 0; backup_map[i][j]; ++j)
            backup_map[i][j] == 'X' ? ++count : 0;
    return (count);
}

int is_boxes_stucked(char **map, char **backup_map)
{
    int stucked = 0;

    for (int i = 0; map[i]; ++i) {
        for (int j = 0; map[i][j]; ++j) {
            map[i][j] == 'X' ? stucked +=
            check_stucked(i, j, map) : 0;
        }
    }
    if (stucked == count_x(backup_map)) {
        return (1);
    }
    return (0);
}
