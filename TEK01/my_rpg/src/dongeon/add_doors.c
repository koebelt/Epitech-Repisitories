/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** add_doors
*/

#include "dongeon.h"

void add_doors_one(dongeon_room_t *element, char **map, sfVector2i pos,
window_t *window)
{
    if (map[pos.y + 1] && map[pos.y + 1][pos.x] == '-') {
        init_sprite(&element->doors[0].sprite, (sprite_info_t){640, 576, 2,
        0, 0, 0, 0, "assets/dongeon/door_front.png"}, window);
        element->doors[0].pos = (sfVector2i) {pos.x, pos.y + 2};
    } else {
        element->doors[0].pos = (sfVector2i) {-1, -1};
        init_sprite(&element->doors[0].sprite, (sprite_info_t){640, 576, 2,
        0, 0, 0, 0, "assets/dongeon/wall_front.png"}, window);
    }
}

void add_doors_two(dongeon_room_t *element, char **map, sfVector2i pos,
window_t *window)
{
    if (pos.y - 1 >= 0 && map[pos.y - 1][pos.x] == '-') {
        init_sprite(&element->doors[1].sprite, (sprite_info_t){640, 64, 2,
        0, 0, 0, 0, "assets/dongeon/door_front.png"}, window);
        element->doors[1].pos = (sfVector2i) {pos.x, pos.y - 2};
    } else {
        element->doors[1].pos = (sfVector2i) {-1, -1};
        init_sprite(&element->doors[1].sprite, (sprite_info_t){640, 64, 2,
        0, 0, 0, 0, "assets/dongeon/wall_front.png"}, window);
    }
}

void add_doors_three(dongeon_room_t *element, char **map, sfVector2i pos,
window_t *window)
{
    if (map[pos.y][pos.x + 1] == '-') {
        init_sprite(&element->doors[2].sprite, (sprite_info_t){928, 290, 2,
        0, 0, 0, 0, "assets/dongeon/door_side.png"}, window);
        element->doors[2].pos = (sfVector2i) {pos.x + 2, pos.y};
    } else {
        element->doors[2].pos = (sfVector2i) {-1, -1};
        init_sprite(&element->doors[2].sprite, (sprite_info_t){928, 290, 2,
        0, 0, 0, 0, "assets/dongeon/wall_side.png"}, window);
    }
}

void add_doors(dongeon_room_t *element, char **map, sfVector2i pos,
window_t *window)
{
    add_doors_one(element, map, pos, window);
    add_doors_two(element, map, pos, window);
    add_doors_three(element, map, pos, window);
    if (pos.x - 1 >= 0 && map[pos.y][pos.x - 1] == '-') {
        init_sprite(&element->doors[3].sprite, (sprite_info_t){352, 290, 2,
        0, 0, 0, 0, "assets/dongeon/door_side.png"}, window);
        element->doors[3].pos = (sfVector2i) {pos.x - 2, pos.y};
    } else {
        element->doors[3].pos = (sfVector2i) {-1, -1};
        init_sprite(&element->doors[3].sprite, (sprite_info_t){352, 290, 2,
        0, 0, 0, 0, "assets/dongeon/wall_side.png"}, window);
    }
}

void link_doors(dongeon_room_t *list)
{
    dongeon_room_t *tmp = list;

    while (tmp != NULL) {
        for (int i = 0; i < 4; ++i)
            (tmp->doors[i].pos.x != -1) ? tmp->doors[i].room =
            check_specified_room(list, tmp->doors[i].pos) : 0;
        tmp = tmp->next;
    }
}