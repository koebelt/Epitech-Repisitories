/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** animate_player_ext
*/

#include "exterior.h"

void animate_player_ext_next(player_ext_t *player, window_t *window,
float speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        move_player_ext(player, window, -speed, 0);
        player->sprite.rect.top = 64;
        player->walking = 1;
    } if (sfKeyboard_isKeyPressed(sfKeyD)) {
        move_player_ext(player, window, speed, 0);
        player->sprite.rect.top = 0;
        player->walking = 1;
    }
}

void animate_player_ext_next_next(player_ext_t *player, window_t *window,
float speed)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        move_player_ext(player, window, 0, -speed);
        player->sprite.rect.top = 96;
        player->walking = 1;
    } if (sfKeyboard_isKeyPressed(sfKeyS)) {
        move_player_ext(player, window, 0, speed);
        player->sprite.rect.top = 32;
        player->walking = 1;
    }
}

void animate_player_ext(player_ext_t *player, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0 - player->t_0;
    float speed = sfKeyboard_isKeyPressed(sfKeyLShift) ? SPEED : PLAYER_SPEED;

    if (seconds > 0.016) {
        animate_player_ext_next(player, window, speed);
        animate_player_ext_next_next(player, window, speed);
        player->t_0 = time.microseconds / 1000000.0;
    }
    if (player->walking)
        animate_sprite(&player->sprite, window, 4);
    else {
        player->sprite.rect.left = 0;
        sfRenderWindow_drawSprite(window->window, player->sprite.sprite, NULL);
    }
}