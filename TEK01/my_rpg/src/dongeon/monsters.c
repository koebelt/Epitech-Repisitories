/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** monsters
*/

#include "dongeon.h"

int is_wall_collision_monster_next(sfImage *img, float i, sfFloatRect rect,
float scale)
{
    float rect_left = rect.left / scale;
    float rect_width = rect.width / scale;

    for (float j = rect_left; j < (rect_left + rect_width); ++j) {
        if (sfColor_toInteger(sfImage_getPixel(img, j, i)) ==
        sfColor_toInteger(sfRed) || sfColor_toInteger(sfImage_getPixel(img,
        j, i)) == sfColor_toInteger(sfBlue))
            return (0);
    }
    return (1);
}

int is_wall_collision_monster(sfFloatRect rect, sfImage *img, float scale)
{
    float rect_top = rect.top / scale;
    float rect_height = rect.height / scale;

    for (float i = rect_top; i < (rect_top + rect_height); i++)
        if (is_wall_collision_monster_next(img, i, rect, scale) == 0)
            return (0);
    return (1);
}

void set_suitable_positions(monster_t *monster, dongeon_room_t *room)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(monster->sprite.sprite);
    int is_suitable = 0;

    while (!is_suitable) {
        rect.top = rand() % (580 - 90) + 90;
        rect.left = rand() % (930 - 380) + 380;
        is_suitable = is_wall_collision_monster(rect,
        room->collisions, room->sprite.scale.x);
    }
    monster->sprite.pos = (sfVector2f){rect.left, rect.top};
    sfSprite_setPosition(monster->sprite.sprite, monster->sprite.pos);
}

void summon_monsters(dongeon_room_t *room, window_t *window)
{
    int number = rand() % (MAX_MONSTER - MIN_MONSTER) + MIN_MONSTER;

    for (int i = 0; i < number; i++)
        summon_monster(&room->monsters, window, room);
}

void set_monster_orientation(monster_t *monster,
sfVector2f tmp)
{
    sfFloatRect box = sfSprite_getGlobalBounds(monster->sprite.sprite);

    if (tmp.x < 0 && monster->sprite.scale.x > 0) {
        monster->sprite.scale.x *= -1;
        monster->sprite.pos.x += box.width;
        monster->attack_range.width *= -1;
    } else if (tmp.x > 0 && monster->sprite.scale.x < 0) {
        monster->sprite.scale.x *= -1;
        monster->sprite.pos.x -= box.width;
        monster->attack_range.width *= -1;
    }
    sfSprite_setPosition(monster->sprite.sprite, monster->sprite.pos);
    sfSprite_setScale(monster->sprite.sprite, monster->sprite.scale);
}