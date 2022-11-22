/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** init_rooms
*/

#include "dongeon.h"

void init_room_three(dongeon_room_t *element, window_t *window, int type)
{
    switch (type) {
        case 6:
            init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 0,
            0, "assets/dongeon/room_6.png"}, window);
            element->collisions =
            sfImage_createFromFile("assets/dongeon/room_6_collisions.png");
            break;
        case 9:
            init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 0,
            0, "assets/dongeon/room_9.png"}, window);
            element->collisions =
            sfImage_createFromFile("assets/dongeon/room_9_collisions.png");
            break;
    }
}

void init_room_two(dongeon_room_t *element, window_t *window, int type)
{
    switch (type) {
        case 4:
            init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 0,
            0, "assets/dongeon/room_4.png"}, window);
            element->collisions =
            sfImage_createFromFile("assets/dongeon/room_4_collisions.png");
            break;
        case 5:
            init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 0,
            0, "assets/dongeon/room_5.png"}, window);
            element->collisions =
            sfImage_createFromFile("assets/dongeon/room_5_collisions.png");
            break;
        default :
            init_room_three(element, window, type);
    }
}

void init_room_one(dongeon_room_t *element, window_t *window, int type)
{
    switch (type) {
        case 2:
            init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 0,
            0, "assets/dongeon/room_2.png"}, window);
            element->collisions =
            sfImage_createFromFile("assets/dongeon/room_2_collisions.png");
            break;
        case 3:
            init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 0,
            0, "assets/dongeon/room_3.png"}, window);
            element->collisions =
            sfImage_createFromFile("assets/dongeon/room_3_collisions.png");
            break;
        default :
            init_room_two(element, window, type);
    }
}

void init_specific_room_type(dongeon_room_t *element, window_t *window)
{
    int type = element->type;

    switch (type) {
        case 0:
            init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 0,
            0, "assets/dongeon/room_0.png"}, window);
            element->collisions =
            sfImage_createFromFile("assets/dongeon/room_0_collisions.png");
            break;
        case 1:
            init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 0,
            0, "assets/dongeon/room_1.png"}, window);
            element->collisions =
            sfImage_createFromFile("assets/dongeon/room_1_collisions.png");
            break;
        default :
            init_room_one(element, window, type);
    }
}

void add_room(dongeon_room_t **list, char **map, sfVector2i pos,
window_t *window)
{
    dongeon_room_t *element;

    element = malloc(sizeof(*element));
    element->type = map[pos.y][pos.x] - '0';
    init_specific_room_type(element, window);
    add_doors(element, map, pos, window);
    element->pos = pos;
    element->monsters = NULL;
    element->miscs = NULL;
    if (element->type == 9)
        create_misc(&element->miscs, window, (sprite_info_t){640, 320, 2, 0, 0,
        0, 0, "assets/dongeon/chest.png"}, 0);
    if (element->type != 0 && element->type != 9)
        summon_monsters(element, window);
    element->next = *list;
    *list = element;
}