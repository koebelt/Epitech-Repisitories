/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** animate_player_dong
*/

#include "dongeon.h"

void animate_player_dong_start(player_dong_t *player, window_t *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        player->sprite.scale.x > 0 ? player->sprite.pos.x += 50 : 0;
        move_player_dong(player, -SPEED - window->inventory.speed_info / 3, 0);
        player->sprite.rect.top = 32;
        player->sprite.scale.x *= player->sprite.scale.x < 0 ? 1 : -1;
        player->walking = 1;
    } if (sfKeyboard_isKeyPressed(sfKeyD)) {
        player->sprite.scale.x < 0 ? player->sprite.pos.x -= 50 : 0;
        move_player_dong(player, SPEED + window->inventory.speed_info / 3, 0);
        player->sprite.rect.top = 32;
        player->sprite.scale.x *= player->sprite.scale.x < 0 ? -1 : 1;
        player->walking = 1;
    }
}

void animate_player_dong_start_second(player_dong_t *player, window_t *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        move_player_dong(player, 0, -SPEED - window->inventory.speed_info / 3);
        player->sprite.rect.top = 32;
        player->walking = 1;
    } if (sfKeyboard_isKeyPressed(sfKeyS)) {
        move_player_dong(player, 0, SPEED + window->inventory.speed_info / 3);
        player->sprite.rect.top = 32;
        player->walking = 1;
    }
}

void animate_player_dong_end_next(player_dong_t *player, window_t *window,
float prev_left)
{
    if (player->sprite.rect.left >= 4 * player->sprite.rect.width) {
        player->attacking = 0;
        player->sprite.rect.left = 0;
    }
    if (player->sprite.rect.left == 3 * player->sprite.rect.width &&
    prev_left != player->sprite.rect.left) {
        create_spell(&player->spell, window, player,
        player->sprite.scale.x > 0 ? SPELL_SPEED : -SPELL_SPEED);
    }
}

void animate_player_dong_end(player_dong_t *player, window_t *window,
float prev_left)
{
    if (player->walking && !player->attacking)
        animate_sprite(&player->sprite, window, 6);
    else if (player->attacking) {
        animate_sprite_attack(&player->sprite, window, 5, 0.2 - (0.01 *
        window->inventory.attack_speed_info));
        animate_player_dong_end_next(player, window, prev_left);
    } else {
        player->sprite.rect.top = 0;
        animate_sprite(&player->sprite, window, 4);
    }
}

void animate_player_dong(player_dong_t *player, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0 - player->t_0;
    float prev_left = player->sprite.rect.left;

    if (seconds > 0.016 && !sfKeyboard_isKeyPressed(sfKeySpace) &&
    !player->attacking) {
        animate_player_dong_start(player, window);
        animate_player_dong_start_second(player, window);
        player->t_0 = time.microseconds / 1000000.0;
    } else if (sfKeyboard_isKeyPressed(sfKeySpace) && !player->attacking) {
        player->sprite.rect.top = 64;
        player->sprite.rect.left = 0;
        sfSprite_setTextureRect(player->sprite.sprite, player->sprite.rect);
        player->walking = 0;
        player->attacking = 1;
    }
    animate_player_dong_end(player, window, prev_left);
}