/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** destroy_items
*/

#include "items.h"

void destroy_items_next(window_t *window, item_t **temp, item_t **prev)
{
    if ((*temp)->equiped == 0 &&
    mouse_hover_item((*temp)->item.sprite, window->mouse, *temp, window) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        if (*prev == NULL)
            window->item = window->item->next;
        else
            (*prev)->next = (*temp)->next;
        window->inventory_tab[(*temp)->y][(*temp)->x].id = -1;
    }
    *prev = *temp;
    *temp = (*temp)->next;
}

void destroy_item_mid(window_t *window, item_t **prev, item_t **temp)
{
    window->mouse.x = window->mouse.x - 120 +
    window->ext.player.sprite.pos.x - 500;
    window->mouse.y = window->mouse.y + 40 +
    window->ext.player.sprite.pos.y - 400;
    if (mouse_hover(window->inventory.select.sprite, window->mouse) == 1 &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        window->inventory.removing = 0;
    window->inventory.bin_temp.pos.x = window->mouse.x - 20;
    window->inventory.bin_temp.pos.y = window->mouse.y - 30;
    while (*temp != NULL)
        destroy_items_next(window, temp, prev);
}

void destroy_items(window_t *window)
{
    item_t *temp = window->item;
    item_t *prev = NULL;

    if (window->inventory.removing == 1)
        destroy_item_mid(window, &prev, &temp);
    else {
        sfRenderWindow_setMouseCursorVisible(window->window, sfTrue);
        window->inventory.bin_temp.pos.x = -3000;
        window->inventory.bin_temp.pos.y = -3000;
    }
    sfSprite_setPosition(window->inventory.bin_temp.sprite,
    window->inventory.bin_temp.pos);
}