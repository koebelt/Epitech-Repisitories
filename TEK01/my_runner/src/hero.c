/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** hero.c
*/

#include "include.h"

void init_hero(sprite_t *hero, sfClock **clock)
{
    hero->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    hero->sprite = sfSprite_create();
    hero->pos.x = 50;
    hero->pos.y = 505;
    hero->scale.x = 6;
    hero->scale.y = 6;
    hero->rect.top = 0;
    hero->rect.left = 0;
    hero->rect.width = 20;
    hero->rect.height = 27;
    hero->texture = sfTexture_createFromFile("ressources/herofix.png", NULL);
    hero->size_text = sfTexture_getSize(hero->texture);
    sfSprite_setTexture(hero->sprite, hero->texture, sfFalse);
}

void anim_hero(hero_t *hero, sfClock **clock, sfRenderWindow **window)
{
    sfTime time = sfClock_getElapsedTime(*clock);
    float seconds = time.microseconds / 1000000.0 - hero->sprite.t_0;
    hero->sprite.rect.left = 0;
    if (seconds > 0.12) {
        if (hero->sprite.rect.top >= 70)
            hero->sprite.rect.top = 0;
        else
            hero->sprite.rect.top += 27;
        hero->sprite.t_0 = sfClock_getElapsedTime(*clock).microseconds /
        1000000.0;
    }
    sfSprite_setTextureRect(hero->sprite.sprite, hero->sprite.rect);
    sfSprite_setPosition(hero->sprite.sprite, hero->sprite.pos);
    sfSprite_setScale(hero->sprite.sprite, hero->sprite.scale);
}
