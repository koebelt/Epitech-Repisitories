/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** player
*/

#include "exterior.h"

void init_player_ext(player_ext_t *player, window_t *window)
{
    player->walking = 0;
    player->t_0 = sfClock_getElapsedTime(window->clock).microseconds /
    1000000.0;
    init_sprite(&player->sprite, (sprite_info_t){900, 600, 3, 0, 0, 16, 16,
    PLAYER_TEXT}, window);
}

void player_ext_mvnt(player_ext_t *player, window_t *window)
{
    if (window->event.type == sfEvtKeyPressed) {
        if (window->event.key.code == sfKeyZ ||
        window->event.key.code == sfKeyQ || window->event.key.code == sfKeyS ||
        window->event.key.code == sfKeyD)
            player->walking = 1;
    } else if (window->event.type == sfEvtKeyReleased) {
        player->walking = 0;
        player->sprite.rect.left = 0;
        sfSprite_setTextureRect(player->sprite.sprite, player->sprite.rect);
    }
}

int is_wall_collision_next(sfImage *image,
sfFloatRect rect, int i)
{
    for (int j = rect.left; j < (rect.left + rect.width); ++j)
        if (sfColor_toInteger(sfImage_getPixel(image, j, i)) == WALL_COLOR)
            return (1);
    return (0);
}

int is_wall_collision(sfImage *image, sfFloatRect rect)
{
    for (int i = rect.top; i < (rect.top + rect.height); i++)
        if (is_wall_collision_next(image, rect, i) == 1)
            return (1);
    return (0);
}

void move_player_ext(player_ext_t *player, window_t *window, int x, int y)
{
    sfFloatRect box = sfSprite_getGlobalBounds(player->sprite.sprite);

    if (window->inventory.open == 0) {
        if (!is_wall_collision(window->ext.map.image, (sfFloatRect)
        {box.left + x + 10, box.top + 20, box.width - 20, box.height - 20}))
            player->sprite.pos.x += x;
        if (!is_wall_collision(window->ext.map.image, (sfFloatRect)
        {box.left + 10, box.top + 20 + y, box.width - 20, box.height - 20}))
            player->sprite.pos.y += y;
    }
    sfSprite_setPosition(player->sprite.sprite, player->sprite.pos);
}