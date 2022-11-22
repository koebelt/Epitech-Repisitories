/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** generate_dongeon
*/

#include "dongeon.h"

dongeon_room_t *check_specified_room(dongeon_room_t *list, sfVector2i pos)
{
    dongeon_room_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->pos.x == pos.x && tmp->pos.y == pos.y)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

dongeon_room_t *find_entrance(dongeon_room_t *list)
{
    dongeon_room_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->type == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

void load_random_map_next(int n, char **map)
{
    switch (n) {
        case 3:
            MAP_4;
            break;
        case 4:
            MAP_5;
            break;
    }
}

void load_random_dongeon(window_t *window, dongeon_t *dongeon)
{
    char *map[6];
    int n = rand() % 5;

    switch (n) {
        case 0:
            MAP_1;
            break;
        case 1:
            MAP_2;
            break;
        case 2:
            MAP_3;
            break;
        default :
            load_random_map_next(n , map);
    }
    load_dongeon(window, dongeon, map);
}

void load_dongeon(window_t *window, dongeon_t *dongeon, char **buffer)
{
    for (int i = 0; buffer[i]; ++i) {
        for (int j = 0; buffer[i][j]; ++j)
            (buffer[i][j] != ' ' && buffer[i][j] != '-') ?
            add_room(&dongeon->list, buffer, (sfVector2i) {j, i}, window) : 0;
    }
    link_doors(dongeon->list);
    dongeon->entrance = find_entrance(dongeon->list);
}