/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** jump.c
*/

#include "include.h"

void init_jump(hero_t *hero, sfClock **clock)
{
    hero->v0 = 70;
    hero->y0 = hero->sprite.pos.y;
    hero->is_jumping = 1;
    hero->is_falling = 0;
    hero->sprite.rect.top = 0;
    hero->sprite.rect.left = 20;
    hero->sprite.t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    hero->time_0 = sfClock_getElapsedTime(*clock).microseconds / 60000.0;
}

int anim_jump(hero_t *hero, window_obj_t *window,
    obstacles_t *obstacles)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 60000.0 - hero->time_0;
    float seconds_anim = time.microseconds / 1000000.0 - hero->sprite.t_0;

    hero->sprite.pos.y = -1 *((0.5 * (-9.81) * pow(seconds, 2)) + 1
    * hero->v0 * seconds - hero->y0);

    if (seconds_anim > 0.13) {
        if (hero->sprite.rect.top >= 120);
        else
            hero->sprite.rect.top += 27;
        hero->sprite.t_0 = sfClock_getElapsedTime(window->clock).microseconds /
        1000000.0;
    }
    sfSprite_setTextureRect(hero->sprite.sprite, hero->sprite.rect);
    sfSprite_setPosition(hero->sprite.sprite, hero->sprite.pos);
    sfRenderWindow_drawSprite(window->window, hero->sprite.sprite, NULL);
}

void init_fall(hero_t *hero, sfClock **clock)
{
    hero->v0 = 0;
    hero->y0 = hero->sprite.pos.y;
    hero->is_falling = 1;
    hero->is_jumping = 0;
    hero->sprite.rect.top = 54;
    hero->sprite.rect.left = 20;
    hero->sprite.t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    hero->time_0 = sfClock_getElapsedTime(*clock).microseconds / 60000.0;
}

int anim_fall(hero_t *hero, window_obj_t *window,
    obstacles_t *obstacles)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 60000.0 - hero->time_0;
    float seconds_anim = time.microseconds / 1000000.0 - hero->sprite.t_0;

    hero->sprite.pos.y = -1 *((0.5 * (-9.81) * pow(seconds, 2)) + 1
    * hero->v0 * seconds - hero->y0);

    if (seconds_anim > 0.13) {
        if (hero->sprite.rect.top >= 120);
        else
            hero->sprite.rect.top += 27;
        hero->sprite.t_0 = sfClock_getElapsedTime(window->clock).microseconds /
        1000000.0;
    }
    sfSprite_setTextureRect(hero->sprite.sprite, hero->sprite.rect);
    sfSprite_setPosition(hero->sprite.sprite, hero->sprite.pos);
}
