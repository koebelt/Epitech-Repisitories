/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** move_monster
*/

#include "dongeon.h"

void move_monster_mid(player_dong_t *player, monster_t *monster,
float monster_pos_x, sfVector2f tmp)
{
    sfFloatRect box = sfSprite_getGlobalBounds(monster->sprite.sprite);

    if (monster->sprite.scale.x < 0)
        monster_pos_x -= box.width;
    if (is_wall_collision_monster((sfFloatRect) {monster_pos_x + tmp.x,
    monster->sprite.pos.y, box.width, box.height}, player->current->collisions,
    player->current->sprite.scale.x))
        monster->sprite.pos.x += tmp.x;
    if (is_wall_collision_monster((sfFloatRect) {monster_pos_x,
    monster->sprite.pos.y + tmp.y, box.width, box.height},
    player->current->collisions, player->current->sprite.scale.x))
        monster->sprite.pos.y += tmp.y;
}

void move_monster(player_dong_t *player, monster_t *monster)
{
    sfVector2f tmp = {player->sprite.pos.x - monster->sprite.pos.x,
    player->sprite.pos.y - monster->sprite.pos.y};
    float monster_pos_x = 0;

    for (; tmp.x > 1 || tmp.x < -1; tmp.x = tmp.x / 1.1, tmp.y = tmp.y / 1.1);
    for (; tmp.y > 1 || tmp.y < -1; tmp.x = tmp.x / 1.1, tmp.y = tmp.y / 1.1);
    set_monster_orientation(monster, tmp);
    monster_pos_x = monster->sprite.pos.x;
    move_monster_mid(player, monster, monster_pos_x, tmp);
    monster->walking = 1;
    monster->sprite.rect.top = 32;
    monster->attack_range.left = monster->sprite.pos.x;
    monster->attack_range.top = monster->sprite.pos.y + 12;
    sfSprite_setPosition(monster->sprite.sprite, monster->sprite.pos);
    sfSprite_setScale(monster->sprite.sprite, monster->sprite.scale);
}