/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** crosshair.c
*/

#include "include.h"

void init_crosshair(sprite_t *crosshair)
{
    crosshair->sprite = sfSprite_create();
    crosshair->pos.x = 0;
    crosshair->pos.y = 0;
    crosshair->scale.x = 4;
    crosshair->scale.y = 4;
    crosshair->rect.top = 0;
    crosshair->rect.left = 0;
    crosshair->rect.width = 15;
    crosshair->rect.height = 15;
    crosshair->shooting = 0;
    crosshair->texture = sfTexture_createFromFile("ressources/crosshair.png",
    NULL);
    crosshair->size_text = sfTexture_getSize(crosshair->texture);
    sfSprite_setTexture(crosshair->sprite, crosshair->texture, sfFalse);
}

void move_crosshair(sprite_t *crosshair, sfVector2i mouse,
    sfRenderWindow **window)
{
    sfSprite_setTextureRect(crosshair->sprite, crosshair->rect);
    crosshair->pos.x = mouse.x - 30;
    crosshair->pos.y = mouse.y - 30;
    crosshair->rect.left = 0;
    if (crosshair->shooting) {
        move_rect(&crosshair->rect, crosshair->size_text.x);
        --crosshair->shooting;
    }
    sfSprite_setPosition(crosshair->sprite, crosshair->pos);
    sfSprite_setScale(crosshair->sprite, crosshair->scale);
    sfRenderWindow_drawSprite(*window, crosshair->sprite, NULL);
}
