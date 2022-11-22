/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** player_and_door_collision
*/

#include "dongeon.h"

sfVector2f set_room_player_pos(int i)
{
    switch(i) {
        case 0:
            return ((sfVector2f){630, 110});
        case 1:
            return ((sfVector2f){630, 500});
        case 2:
            return ((sfVector2f){400, 320});
        case 3:
            return ((sfVector2f){830, 320});
    }
    return ((sfVector2f){0, 0});
}

int player_dong_door_collision_next(int i, sfFloatRect door_box,
player_dong_t *player, sfFloatRect player_box)
{
    door_box =
    sfSprite_getGlobalBounds(player->current->doors[i].sprite.sprite);
    if (player->current->doors[i].pos.x != -1) {
        if (sfFloatRect_intersects(&door_box, &player_box, NULL) &&
        player->current->monsters == NULL) {
            player->current = player->current->doors[i].room;
            player->sprite.pos = set_room_player_pos(i);
            player->spell = NULL;
            player->sprite.scale.x < 0 ? player->sprite.pos.x +=
            player_box.width : 0;
            return (0);
        }
    } else if (sfFloatRect_intersects(&door_box, &player_box, NULL))
        return (1);
    return (2);
}

int player_dong_door_collision(player_dong_t *player)
{
    sfFloatRect door_box;
    sfFloatRect player_box = sfSprite_getGlobalBounds(player->sprite.sprite);
    player_box.top += 45;
    player_box.height -= 45;
    int res = 0;

    if (player->sprite.scale.x < 0) {
        player_box.left += 20;
        player_box.width -= 20;
    } else
        player_box.width -= 20;
    for (int i = 0; i < 4; ++i) {
        res = player_dong_door_collision_next(i, door_box, player, player_box);
        if (res < 2)
            return (res);
    }
    sfSprite_setPosition(player->sprite.sprite, player->sprite.pos);
    return (0);
}