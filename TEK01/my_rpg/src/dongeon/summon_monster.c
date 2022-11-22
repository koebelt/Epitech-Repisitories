/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** summon_monster
*/

#include "dongeon.h"

void summon_archer(monster_t *element, window_t *window)
{
    init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 48, 32,
    "assets/dongeon/skeleton_arc.png"}, window);
    element->attack_range = (sfFloatRect){0, 0, 400, 20};
    element->stats = (entity_stats_t){ARCHER_HEALTH, ARCHER_DAMAGE,
    ARCHER_SPEED};
    element->type = 0;
}

void summon_spear(monster_t *element, window_t *window)
{
    init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 48, 32,
    "assets/dongeon/skeleton_spear.png"}, window);
    element->attack_range = sfSprite_getGlobalBounds(element->sprite.sprite);
    element->stats = (entity_stats_t){SPEAR_HEALTH, SPEAR_DAMAGE, SPEAR_SPEED};
    element->type = 1;
}

void summon_skull(monster_t *element, window_t *window)
{
    init_sprite(&element->sprite, (sprite_info_t){0, 0, 2, 0, 0, 48, 32,
    "assets/dongeon/skeleton_skull.png"}, window);
    element->attack_range = sfSprite_getGlobalBounds(element->sprite.sprite);
    element->stats = (entity_stats_t){SKULL_HEALTH, SKULL_DAMAGE, SKULL_SPEED};
    element->type = 2;
}

void summon_monster(monster_t **list, window_t *window, dongeon_room_t *room)
{
    monster_t *element;
    int type = rand() % 3;

    element = malloc(sizeof(*element));
    switch (type) {
        case 0: summon_archer(element, window);
                break;
        case 1: summon_spear(element, window);
                break;
        case 2: summon_skull(element, window);
                break;
    }
    element->spell = NULL;
    element->walking = 0;
    element->attacking = 0;
    set_suitable_positions(element, room);
    element->next = *list;
    *list = element;
}