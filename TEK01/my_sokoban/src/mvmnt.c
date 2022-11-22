/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-thomas.koebel
** File description:
** mvmnt
*/

#include "../include/include.h"

void mv_up(char **map, int key, pos_t p_pos)
{
    int x = p_pos.x;
    int y = p_pos.y;

    if (key == KEY_UP && map[y - 1][x] != '#') {
        if (map[y - 1][x] == 'X' &&  map[y - 2][x] !=
        '#' && map[y - 2][x] != 'X') {
            map[y][x] = ' ';
            map[y - 1][x] = 'P';
            map[y - 2][x] = 'X';
        } else if (map[y - 1][x] != 'X') {
            map[y][x] = ' ';
            map[y - 1][x] = 'P';
        }
    }
}

void mv_down(char **map, int key, pos_t p_pos)
{
    int x = p_pos.x;
    int y = p_pos.y;

    if (key == KEY_DOWN && map[y + 1][x] != '#') {
        if (map[y + 1][x] == 'X' &&  map[y + 2][x] !=
        '#' && map[y + 2][x] != 'X') {
            map[y][x] = ' ';
            map[y + 1][x] = 'P';
            map[y + 2][x] = 'X';
        } else if (map[y + 1][x] != 'X') {
            map[y][x] = ' ';
            map[y + 1][x] = 'P';
        }
    }
}

void mv_right(char **map, int key, pos_t p_pos)
{
    int x = p_pos.x;
    int y = p_pos.y;

    if (key == KEY_RIGHT && map[y][x + 1] != '#') {
        if (map[y][x + 1] == 'X' &&  map[y][x + 2] !=
        '#' && map[y][x + 2] != 'X') {
            map[y][x] = ' ';
            map[y][x + 1] = 'P';
            map[y][x + 2] = 'X';
        } else if (map[y][x + 1] != 'X') {
            map[y][x] = ' ';
            map[y][x + 1] = 'P';
        }
    }
}

void mv_left(char **map, int key, pos_t p_pos)
{
    int x = p_pos.x;
    int y = p_pos.y;

    if (key == KEY_LEFT && map[y][x - 1] != '#') {
        if (map[y][x - 1] == 'X' &&  map[y][x - 2] !=
        '#' && map[y][x - 2] != 'X') {
            map[y][x] = ' ';
            map[y][x - 1] = 'P';
            map[y][x - 2] = 'X';
        } else if (map[y][x - 1] != 'X') {
            map[y][x] = ' ';
            map[y][x - 1] = 'P';
        }
    }
}

int process_key(char **map, char **backup_map, int key, pos_t p_pos)
{
    mv_up(map, key, p_pos);
    mv_down(map, key, p_pos);
    mv_left(map, key, p_pos);
    mv_right(map, key, p_pos);
    if (key == ' ')
        reset_map(map, backup_map);
    return (is_win(map, backup_map));
}