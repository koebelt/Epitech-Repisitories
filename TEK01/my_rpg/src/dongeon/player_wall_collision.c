/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** player_wall_collision
*/

#include "dongeon.h"

sfFloatRect is_wall_collision_dong_start(player_dong_t *player)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(player->sprite.sprite);

    if (player->sprite.scale.x < 0) {
        rect.left += 20;
        rect.width -= 20;
    } else
        rect.width -= 20;
    rect.top += 45;
    rect.height -= 45;
    return (rect);
}

int is_wall_collision_dong_mid(sfImage *image, player_dong_t *player,
sfFloatRect rect, int i)
{
    int rect_left = rect.left / player->current->sprite.scale.x;
    int rect_width = rect.width / player->current->sprite.scale.x;

    for (int j = rect_left; j < (rect_left + rect_width); ++j) {
        if (sfColor_toInteger(sfImage_getPixel(image, j, i)) ==
        sfColor_toInteger(sfRed) ||
        sfColor_toInteger(sfImage_getPixel(image, j, i)) ==
        sfColor_toInteger(sfBlue))
            return (1);
    }
    return (0);
}

int is_wall_collision_dong(sfImage *image, player_dong_t *player)
{
    sfFloatRect rect = is_wall_collision_dong_start(player);
    int rect_top = rect.top / player->current->sprite.scale.x;
    int rect_height = rect.height / player->current->sprite.scale.x;

    for (int i = rect_top; i < (rect_top + rect_height); i++)
        if (is_wall_collision_dong_mid(image, player, rect, i) == 1)
            return (1);
    return (0);
}