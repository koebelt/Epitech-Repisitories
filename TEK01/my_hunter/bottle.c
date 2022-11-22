/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** bottle.c
*/

#include "include.h"

void bottle_random_physics(bottle_t *bottle)
{
    srand(time(NULL));
    int angle = rand() % (45 - 10 + 1) + 10;
    bottle->a = angle * 3.14159265 / 180;
    bottle->y0 = rand() % (500 - 100) + 100;
    bottle->V0 = rand() % (100 - 50) + 50;
    bottle->x0 = rand() > (RAND_MAX / 2) ? -30 : -1080;
    bottle->is_left = bottle->x0 == -1080 ? -1 : 1;
    bottle->rot_rate = (rand() % (10 - 5 + 1) + 5) * bottle->is_left;
}

void init_bottle(bottle_t *bottle)
{
    bottle_random_physics(bottle);
    bottle->sprite = sfSprite_create();
    bottle->pos.x = 0;
    bottle->pos.y = 0;
    bottle->scale.x = 4;
    bottle->scale.y = 4;
    bottle->rect.top = 0;
    bottle->rect.width = 15;
    bottle->rect.height = 32;
    bottle->breaked = 0;
    bottle->texture = sfTexture_createFromFile("ressources/Bottles.png", NULL);
    bottle->size_text = sfTexture_getSize(bottle->texture);
    sfSprite_setTexture(bottle->sprite, bottle->texture, sfFalse);
    sfSprite_setTextureRect(bottle->sprite, bottle->rect);
}

void calc_one_bottle(bottle_t *bottle, sfRenderWindow **window,
    sfClock *mvmnt_clock)
{
    sfTime time = sfClock_getElapsedTime(mvmnt_clock);
    float seconds = time.microseconds / 100000.0;
    float g = 9.81;

    bottle->pos.x = bottle->is_left *(cos(bottle->a) * bottle->V0 * seconds
    + bottle->x0);
    bottle->pos.y = -1 *((0.5 * (-g) * pow(seconds, 2)) + sin(bottle->a)
    * bottle->V0 * seconds - bottle->y0);
    sfSprite_setTextureRect(bottle->sprite, bottle->rect);
    sfSprite_setPosition(bottle->sprite, bottle->pos);
    sfSprite_rotate(bottle->sprite, bottle->rot_rate);
    sfSprite_setScale(bottle->sprite, bottle->scale);
    if (!bottle->breaked)
        sfRenderWindow_drawSprite(*window, bottle->sprite, NULL);
}
