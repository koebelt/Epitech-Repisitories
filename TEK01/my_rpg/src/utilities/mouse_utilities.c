/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** mouse_utilities
*/

#include "../../include/include.h"

int mouse_click(sfSprite *sprite_button, sfVector2i mouse)
{
    sfFloatRect mouse_rect = sfSprite_getGlobalBounds(sprite_button);

    if (sfFloatRect_contains(&mouse_rect, mouse.x, mouse.y))
        return (1);
    return (0);
}

int mouse_hover(sfSprite *sprite_button, sfVector2i mouse)
{
    sfFloatRect mouse_rect = sfSprite_getGlobalBounds(sprite_button);
    sfColor color;
    int num = 0;

    if (sfFloatRect_contains(&mouse_rect, mouse.x, mouse.y)) {
        color = sfColor_fromRGBA(255, 255, 255, 150);
        num += 1;
    } else
        color = sfColor_fromRGBA(255, 255, 255, 255);
    sfSprite_setColor(sprite_button, color);
    return (num);
}