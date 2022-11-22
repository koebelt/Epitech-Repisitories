/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** disp_bottles2.c
*/

#include "include.h"

void disp_bwhine(button_t *bottle3, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    if (mouse_pos.x > bottle3->sprite.pos.x && mouse_pos.x <
    (bottle3->sprite.pos.x + bottle3->sprite.size_text.x *
    bottle3->sprite.scale.x) && mouse_pos.y > bottle3->sprite.pos.y &&
    mouse_pos.y < (bottle3->sprite.pos.y + bottle3->sprite.size_text.y *
    bottle3->sprite.scale.y))
        sfRenderWindow_drawText(*window, bottle3->text, NULL);
    sfSprite_setPosition(bottle3->sprite.sprite, bottle3->sprite.pos);
    sfRenderWindow_drawSprite(*window, bottle3->sprite.sprite, NULL);
}

void disp_gwhine(button_t *bottle4, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    if (mouse_pos.x > bottle4->sprite.pos.x && mouse_pos.x <
    (bottle4->sprite.pos.x + bottle4->sprite.size_text.x *
    bottle4->sprite.scale.x) && mouse_pos.y > bottle4->sprite.pos.y &&
    mouse_pos.y < (bottle4->sprite.pos.y + bottle4->sprite.size_text.y *
    bottle4->sprite.scale.y))
        sfRenderWindow_drawText(*window, bottle4->text, NULL);
    sfSprite_setPosition(bottle4->sprite.sprite, bottle4->sprite.pos);
    sfRenderWindow_drawSprite(*window, bottle4->sprite.sprite, NULL);
}

void disp_champagne(button_t *bottle5, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    if (mouse_pos.x > bottle5->sprite.pos.x && mouse_pos.x <
    (bottle5->sprite.pos.x + bottle5->sprite.size_text.x *
    bottle5->sprite.scale.x) && mouse_pos.y > bottle5->sprite.pos.y &&
    mouse_pos.y < (bottle5->sprite.pos.y + bottle5->sprite.size_text.y *
    bottle5->sprite.scale.y))
        sfRenderWindow_drawText(*window, bottle5->text, NULL);
    sfSprite_setPosition(bottle5->sprite.sprite, bottle5->sprite.pos);
    sfRenderWindow_drawSprite(*window, bottle5->sprite.sprite, NULL);
}
