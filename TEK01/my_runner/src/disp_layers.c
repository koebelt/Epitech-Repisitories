/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** disp_layers.c
*/

#include "include.h"

void calc_layers(background_t *background, sfRenderWindow **window)
{
    for (int i = 0; i < 3; ++i) {
        background->layers[1].sprite[i].pos.x -= background->velocity * 0.05;
        if (background->layers[1].sprite[i].pos.x <= -200 * 8)
            background->layers[1].sprite[i].pos.x = 200 * 8 * 2;
        sfSprite_setPosition(background->layers[1].sprite[i].sprite,
        background->layers[1].sprite[i].pos);
        sfRenderWindow_drawSprite(*window,
        background->layers[1].sprite[i].sprite, NULL);
    }
    for (int i = 0; i < 3; ++i) {
        background->layers[0].sprite[i].pos.x -= background->velocity * 0.3;
        if (background->layers[0].sprite[i].pos.x <= -192 * 8)
            background->layers[0].sprite[i].pos.x = 191 * 8 * 2;
        sfSprite_setPosition(background->layers[0].sprite[i].sprite,
        background->layers[0].sprite[i].pos);
        sfRenderWindow_drawSprite(*window,
        background->layers[0].sprite[i].sprite, NULL);
    }
}

void calc_layers_part_two(background_t *background, sfRenderWindow **window)
{
    for (int i = 0; i < 6; ++i) {
        background->layers[6].sprite[i].pos.x -= background->velocity * 0.1;
        if (background->layers[6].sprite[i].pos.x <= -22 * 8)
            renit_cloud2(&background->layers[6], i);
        sfSprite_setPosition(background->layers[6].sprite[i].sprite,
        background->layers[6].sprite[i].pos);
        sfRenderWindow_drawSprite(*window,
        background->layers[6].sprite[i].sprite, NULL);
    }
    for (int i = 0; i < 3; ++i) {
        background->layers[2].sprite[i].pos.x -= background->velocity * 0.9;
        if (background->layers[2].sprite[i].pos.x <= -208 * 8)
            background->layers[2].sprite[i].pos.x = 207 * 8 * 2;
        sfSprite_setPosition(background->layers[2].sprite[i].sprite,
        background->layers[2].sprite[i].pos);
        sfRenderWindow_drawSprite(*window,
        background->layers[2].sprite[i].sprite, NULL);
    }
}

void calc_layers_part_three(background_t *background, sfRenderWindow **window)
{
    for (int i = 0; i < 3; ++i) {
        background->layers[3].sprite[i].pos.x -= background->velocity * 0.9;
        if (background->layers[3].sprite[i].pos.x <= -50 * 8)
            background->layers[3].sprite[i].pos.x = (rand() %
            (200 - 80) + 80) * 8 * 2;
        sfSprite_setPosition(background->layers[3].sprite[i].sprite,
        background->layers[3].sprite[i].pos);
        sfRenderWindow_drawSprite(*window,
        background->layers[3].sprite[i].sprite, NULL);
    }
    for (int i = 0; i < 3; ++i) {
        background->layers[4].sprite[i].pos.x -= background->velocity * 0.9;
        if (background->layers[4].sprite[i].pos.x <= -35 * 8)
            background->layers[4].sprite[i].pos.x = (rand() %
            (200 - 80) + 80) * 8 * 2;
        sfSprite_setPosition(background->layers[4].sprite[i].sprite,
        background->layers[4].sprite[i].pos);
        sfRenderWindow_drawSprite(*window,
        background->layers[4].sprite[i].sprite, NULL);
    }
}

void calc_layers_part_four(background_t *background, sfRenderWindow **window)
{
    for (int i = 0; i < 2; ++i) {
        background->layers[5].sprite[i].pos.x -= background->velocity * 0.2;
        if (background->layers[5].sprite[i].pos.x <= -80 * 8)
            renit_cloud(&background->layers[5], i);
        sfSprite_setPosition(background->layers[5].sprite[i].sprite,
        background->layers[5].sprite[i].pos);
        sfRenderWindow_drawSprite(*window,
        background->layers[5].sprite[i].sprite, NULL);
    }
}
