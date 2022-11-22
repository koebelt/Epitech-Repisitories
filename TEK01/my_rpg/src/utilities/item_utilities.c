/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** item_utilities
*/

#include "../../include/include.h"

void give_stats(item_t *temp, item_info_t info)
{
    temp->stats.damage = info.damage;
    temp->stats.attack_speed = info.attack_speed;
    temp->stats.speed = info.speed;
    temp->stats.armor = info.armor;
    temp->stats.type = info.type;
    temp->placed = 0;
    temp->equiped = 0;
    temp->equiped_x = -1;
    temp->equiped_y = -1;
    temp->next = NULL;
}

void init_item(window_t *window, item_info_t info, sprite_info_t sprite)
{
    item_t *temp = window->item;
    item_t *prev = NULL;

    while (temp != NULL) {
        prev = temp;
        temp = temp->next;
    }
    temp = malloc(sizeof(item_t));
    if (prev != NULL) {
        temp->id = prev->id + 1;
        prev->next = temp;
    } else {
        window->item = temp;
        temp->id = 1;
    }
    give_stats(temp, info);
    init_sprite(&temp->item, sprite, window);
    sfSprite_setOrigin(temp->item.sprite,
    (sfVector2f){temp->item.size_text.x / 2, temp->item.size_text.y / 2});
}