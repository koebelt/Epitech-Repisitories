/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** disp_bottles1.c
*/

#include "include.h"

void disp_wwhine(button_t *bottle0, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    if (mouse_pos.x > bottle0->sprite.pos.x && mouse_pos.x <
    (bottle0->sprite.pos.x + bottle0->sprite.size_text.x *
    bottle0->sprite.scale.x) && mouse_pos.y > bottle0->sprite.pos.y &&
    mouse_pos.y < (bottle0->sprite.pos.y + bottle0->sprite.size_text.y *
    bottle0->sprite.scale.y))
        sfRenderWindow_drawText(*window, bottle0->text, NULL);
    sfSprite_setPosition(bottle0->sprite.sprite, bottle0->sprite.pos);
    sfRenderWindow_drawSprite(*window, bottle0->sprite.sprite, NULL);
}

void disp_rwhine(button_t *bottle1, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    if (mouse_pos.x > bottle1->sprite.pos.x && mouse_pos.x <
    (bottle1->sprite.pos.x + bottle1->sprite.size_text.x *
    bottle1->sprite.scale.x) && mouse_pos.y > bottle1->sprite.pos.y &&
    mouse_pos.y < (bottle1->sprite.pos.y + bottle1->sprite.size_text.y *
    bottle1->sprite.scale.y))
        sfRenderWindow_drawText(*window, bottle1->text, NULL);
    sfSprite_setPosition(bottle1->sprite.sprite, bottle1->sprite.pos);
    sfRenderWindow_drawSprite(*window, bottle1->sprite.sprite, NULL);
}

void disp_wiskey(button_t *bottle2, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    if (mouse_pos.x > bottle2->sprite.pos.x && mouse_pos.x <
    (bottle2->sprite.pos.x + bottle2->sprite.size_text.x *
    bottle2->sprite.scale.x) && mouse_pos.y > bottle2->sprite.pos.y &&
    mouse_pos.y < (bottle2->sprite.pos.y + bottle2->sprite.size_text.y *
    bottle2->sprite.scale.y))
        sfRenderWindow_drawText(*window, bottle2->text, NULL);
    sfSprite_setPosition(bottle2->sprite.sprite, bottle2->sprite.pos);
    sfRenderWindow_drawSprite(*window, bottle2->sprite.sprite, NULL);
}
