/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** hunter.c
*/

#include "include.h"

void init_hunter(sprite_t *hunter)
{
    hunter->sprite = sfSprite_create();
    hunter->pos.x = 510;
    hunter->pos.y = 588;
    hunter->scale.x = 6;
    hunter->scale.y = 6;
    hunter->rect.top = 0;
    hunter->rect.left = 0;
    hunter->rect.width = 14;
    hunter->rect.height = 22;
    hunter->texture = sfTexture_createFromFile("ressources/idlewh.png", NULL);
    hunter->size_text = sfTexture_getSize(hunter->texture);
    sfSprite_setTexture(hunter->sprite, hunter->texture, sfFalse);
}

void anim_hunter(sprite_t *hunter, sfClock **clock, sfVector2i mouse,
    sfRenderWindow **window)
{
    sfSprite_setTextureRect(hunter->sprite, hunter->rect);
    sfSprite_setPosition(hunter->sprite, hunter->pos);
    if (mouse.x < hunter->pos.x)
        hunter->scale.x = hunter->scale.x > 0 ? -1 * hunter->scale.x :
        hunter->scale.x;
    else
        hunter->scale.x = hunter->scale.x < 0 ? -1 * hunter->scale.x :
        hunter->scale.x;
    sfSprite_setScale(hunter->sprite, hunter->scale);
    sfTime time = sfClock_getElapsedTime(*clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        move_rect(&hunter->rect, hunter->size_text.x);
        sfClock_restart(*clock);
    }
    sfRenderWindow_drawSprite(*window, hunter->sprite, NULL);
}

void init_hand(sprite_t *hand)
{
    hand->sprite = sfSprite_create();
    hand->pos.x = 510;
    hand->pos.y = 637;
    hand->scale.x = 6;
    hand->scale.y = 6;
    hand->rect.top = 0;
    hand->rect.left = 0;
    hand->rect.width = 42;
    hand->rect.height = 13;
    hand->shooting = 0;
    hand->texture = sfTexture_createFromFile("ressources/hand2.png", NULL);
    hand->size_text = sfTexture_getSize(hand->texture);
    sfSprite_setTexture(hand->sprite, hand->texture, sfFalse);
}

void calc_hand(sprite_t *hand, sfVector2i mouse, sfRenderWindow **window,
    sfClock **clock)
{
    sfTime time = sfClock_getElapsedTime(*clock);
    float seconds = time.microseconds / 1000000.0;
    float angle = atan2(mouse.y - hand->pos.y, mouse.x - hand->pos.x)
    * 180 / 3.14159265;

    sfSprite_setPosition(hand->sprite, hand->pos);
    sfSprite_setRotation(hand->sprite, angle);
    if (mouse.x < hand->pos.x)
        hand->scale.y = hand->scale.y > 0 ? -1 * hand->scale.y : hand->scale.y;
    else
        hand->scale.y = hand->scale.y < 0 ? -1 * hand->scale.y : hand->scale.y;
    if (hand->shooting && seconds > 0.1) {
        move_rect(&hand->rect, hand->size_text.x);
        sfClock_restart(*clock);
        --hand->shooting;
    } else if (!hand->shooting)
        hand->rect.left = 0;
    sfSprite_setTextureRect(hand->sprite, hand->rect);
    sfSprite_setScale(hand->sprite, hand->scale);
    sfRenderWindow_drawSprite(*window, hand->sprite, NULL);
}
