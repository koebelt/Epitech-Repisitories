/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-thomas.koebel
** File description:
** map
*/

#include "../include/include.h"

void print_map(char **map)
{
    int lines = 0;

    for (; map[lines]; ++lines);
    for (int i = 0; map[i]; ++i)
        mvprintw((LINES / 2) - (lines / 2) + i, (COLS / 2) -
        (my_strlen(map[0]) / 2), map[i]);
}

void put_o_in_map(char **map, char **backup_map)
{
    for (int i = 0; map[i]; ++i) {
        for (int j = 0; map[i][j]; ++j) {
            backup_map[i][j] == 'O' && map[i][j] == ' ' ? map[i][j] = 'O' : 0;
        }
    }
}

pos_t get_p_pos(char **map)
{
    pos_t p_pos = {0, 0};

    for (int i = 0; map[i]; ++i)
        for (int j = 0; map[i][j]; ++j) {
            p_pos.x = map[i][j] == 'P' ? j : p_pos.x;
            p_pos.y = map[i][j] == 'P' ? i : p_pos.y;
        }
    return (p_pos);
}

void reset_map(char **map, char **backup_map)
{
    for (int i = 0; backup_map[i]; ++i)
        for (int j = 0; backup_map[i][j]; ++j)
            map[i][j] = backup_map[i][j];
}