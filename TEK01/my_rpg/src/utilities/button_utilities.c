/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** button_utilities
*/

#include "../../include/include.h"

int check_btn(window_t *window, sprite_t *button)
{
    sfFloatRect mouse_rect = sfSprite_getGlobalBounds(button->sprite);

    if (sfFloatRect_contains(&mouse_rect, window->mouse.x, window->mouse.y))
        return (1);
    return (0);
}