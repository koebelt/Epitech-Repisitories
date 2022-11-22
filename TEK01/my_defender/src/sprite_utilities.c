/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** sprite_management
*/

#include "../include/include.h"

sprite_t init_sprite(sprite_info_t sprite_i)
{
    sprite_t new;

    new.sprite = sfSprite_create();
    new.pos.x = sprite_i.pos_x;
    new.pos.y = sprite_i.pos_y;
    new.scale.x = sprite_i.scale_x;
    new.scale.y = sprite_i.scale_y;
    new.texture = sfTexture_createFromFile(sprite_i.path_text, NULL);
    new.size_text = sfTexture_getSize(new.texture);
    sfSprite_setScale(new.sprite, new.scale);
    sfSprite_setPosition(new.sprite, new.pos);
    sfSprite_setTexture(new.sprite, new.texture, sfFalse);
    if (sprite_i.rect_height != 0) {
        new.rect.top = sprite_i.rect_x;
        new.rect.left = sprite_i.rect_y;
        new.rect.height = sprite_i.rect_height;
        new.rect.width = sprite_i.rect_width;
        sfSprite_setTextureRect(new.sprite, new.rect);
    }
    return (new);
}

void animate_soldier(soldiers_t *soldier, sfClock **clock,
sfRenderWindow *window, sprite_t *sprite)
{
    sfTime time = sfClock_getElapsedTime(*clock);
    float seconds = time.microseconds / 1000000.0 - soldier->t_0;

    if (seconds > 0.12) {
        if (sprite->rect.left >= sprite->size_text.x - sprite->rect.width)
            sprite->rect.left = 0;
        else
            sprite->rect.left += sprite->rect.width;
        soldier->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    }
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfRenderWindow_drawSprite(window, sprite->sprite, sfFalse);
}

void animate_health_bar(soldiers_t *soldier, sfRenderWindow *window)
{
    soldier->health_bar.rect.width = soldier->health * 327 /
    soldier->max_health;
    sfSprite_setTextureRect(soldier->health_bar.sprite,
    soldier->health_bar.rect);
    sfRenderWindow_drawSprite(window, soldier->health_bar.sprite, sfFalse);
}

void button_hover_simple_animation(sfVector2i mouse, sprite_t *button)
{
    sfFloatRect collision_box = sfSprite_getGlobalBounds(button->sprite);

    if (sfFloatRect_contains(&collision_box, mouse.x, mouse.y)) {
        button->rect.left = button->rect.width;
    } else
        button->rect.left = 0;
    sfSprite_setTextureRect(button->sprite, button->rect);
}

void button_hover_color_animation(sfVector2i mouse, sprite_t *button)
{
    sfFloatRect collision_box = sfSprite_getGlobalBounds(button->sprite);
    sfColor color;

    if (sfFloatRect_contains(&collision_box, mouse.x, mouse.y)) {
        color = sfColor_fromRGBA(255, 255, 255, 150);
    } else
        color = sfColor_fromRGBA(255, 255, 255, 255);
    sfSprite_setColor(button->sprite, color);
}