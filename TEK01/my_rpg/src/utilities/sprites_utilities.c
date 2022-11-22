/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** sprites_utilities
*/

#include "../../include/include.h"

void init_sprite(sprite_t *new, sprite_info_t sprite_i, window_t *window)
{
    new->sprite = sfSprite_create();
    new->pos.x = sprite_i.pos_x;
    new->pos.y = sprite_i.pos_y;
    new->scale.x = sprite_i.scale;
    new->scale.y = sprite_i.scale;
    new->texture = sfTexture_createFromFile(sprite_i.path_text, NULL);
    new->size_text = sfTexture_getSize(new->texture);
    sfSprite_setScale(new->sprite, new->scale);
    sfSprite_setPosition(new->sprite, new->pos);
    sfSprite_setTexture(new->sprite, new->texture, sfFalse);
    if (sprite_i.rect_height != 0) {
        new->rect.top = sprite_i.rect_top;
        new->rect.left = sprite_i.rect_left;
        new->rect.height = sprite_i.rect_height;
        new->rect.width = sprite_i.rect_width;
        sfSprite_setTextureRect(new->sprite, new->rect);
        new->t_0 = sfClock_getElapsedTime(window->clock).microseconds /
        1000000.0;
    }
}

void animate_sprite(sprite_t *sprite, window_t *window, int nb)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0 - sprite->t_0;

    if (seconds > 0.12) {
        if (sprite->rect.left >= sprite->rect.width * (nb - 1))
            sprite->rect.left = 0;
        else
            sprite->rect.left += sprite->rect.width;
        sprite->t_0 = sfClock_getElapsedTime(window->clock).microseconds /
        1000000.0;
    }
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfRenderWindow_drawSprite(window->window, sprite->sprite, sfFalse);
}

void animate_sprite_attack(sprite_t *sprite, window_t *window, int nb,
float delay)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0 - sprite->t_0;

    if (seconds > delay) {
        if (sprite->rect.left >= sprite->rect.width * (nb - 1))
            sprite->rect.left = 0;
        else
            sprite->rect.left += sprite->rect.width;
        sprite->t_0 = sfClock_getElapsedTime(window->clock).microseconds /
        1000000.0;
    }
    sfSprite_setScale(sprite->sprite, sprite->scale);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfRenderWindow_drawSprite(window->window, sprite->sprite, sfFalse);
}

int change_texture(sprite_t *sprite, char *new_texture)
{
    sfTexture_destroy(sprite->texture);
    sprite->texture = sfTexture_createFromFile(new_texture, NULL);
    if (sprite->texture == NULL)
        return (-1);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    return (0);
}

int load_bar(sprite_t *bar, float percent)
{
    sfIntRect rect = sfSprite_getTextureRect(bar->sprite);
    float new_width = (float) bar->rect.width * (percent / 100.f);

    rect.width = (int) new_width;
    sfSprite_setTextureRect(bar->sprite, rect);
    return (0);
}