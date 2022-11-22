/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** map
*/

#include "exterior.h"

void init_map(map_t *map, window_t *window)
{
    sfTexture *text;

    map->image = sfImage_createFromFile(MAP_TEXT);
    text = sfTexture_createFromImage(map->image, NULL);
    init_sprite(&map->sprite, (sprite_info_t){0, 0, 1, 0, 0, 0, 0, MAP_TEXT},
    window);
    sfSprite_setTexture(map->sprite.sprite, text, sfFalse);
}

void run_map(map_t *map, window_t *window)
{
    sfRenderWindow_drawSprite(window->window, map->sprite.sprite, sfFalse);
}