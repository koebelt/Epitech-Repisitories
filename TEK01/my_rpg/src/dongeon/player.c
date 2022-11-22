/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** player
*/

#include "dongeon.h"

void init_player_dong(player_dong_t *player, window_t *window)
{
    player->attacking = 0;
    player->walking = 0;
    player->spell = NULL;
    player->t_0 =
    sfClock_getElapsedTime(window->clock).microseconds / 1000000.0;
    player->stats = (entity_stats_t){PLAYER_HEALTH, PLAYER_DAMAGE, SPEED};
    init_sprite(&player->sprite, (sprite_info_t){650, 300, 2, 0, 0, 36, 32,
    "assets/dongeon/player.png"}, window);
}

void player_dong_mvnt(player_dong_t *player, window_t *window)
{
    if (window->event.type == sfEvtKeyReleased) {
        player->walking = 0;
        if (!player->attacking)
            player->sprite.rect.left = 0;
        sfSprite_setTextureRect(player->sprite.sprite, player->sprite.rect);
    }
}

void move_player_dong(player_dong_t *player, int x, int y)
{
    int wall_collisions = is_wall_collision_dong(player->current->collisions,
    player);
    int door_collisions = player_dong_door_collision(player);

    if (!wall_collisions && !door_collisions) {
        player->sprite.pos.x += x;
        player->sprite.pos.y += y;
    }
    sfSprite_setPosition(player->sprite.sprite, player->sprite.pos);
    wall_collisions = is_wall_collision_dong(player->current->collisions,
    player);
    door_collisions = player_dong_door_collision(player);
    if (wall_collisions || door_collisions) {
        player->sprite.pos.x -= x;
        player->sprite.pos.y -= y;
    }

    sfSprite_setPosition(player->sprite.sprite, player->sprite.pos);
}