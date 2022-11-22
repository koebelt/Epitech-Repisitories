/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** replace_items
*/

#include "items.h"

void replace_item_third(window_t *window, item_t **item)
{
    if ((*item)->x == 1)
        (*item)->item.pos.x = 745 + window->view_center.x - 500;
    if ((*item)->x == 2)
        (*item)->item.pos.x = 800 + window->view_center.x - 500;
    if ((*item)->x == 3)
        (*item)->item.pos.x = 855 + window->view_center.x - 500;
    if ((*item)->x == 4)
        (*item)->item.pos.x = 910 + window->view_center.x - 500;
}

void replace_item_second(window_t *window, item_t **item)
{
    if ((*item)->y == 4)
        (*item)->item.pos.y = 500 + window->view_center.y - 400;
    if ((*item)->y == 5)
        (*item)->item.pos.y = 555 + window->view_center.y - 400;
    if ((*item)->y == 6)
        (*item)->item.pos.y = 613 + window->view_center.y - 400;
    if ((*item)->x == 0)
        (*item)->item.pos.x = 690 + window->view_center.x - 500;
}

void replace_item(window_t *window, item_t **item)
{
    if ((*item)->y == 0)
        (*item)->item.pos.y = 270 + window->view_center.y - 400;
    if ((*item)->y == 1)
        (*item)->item.pos.y = 328 + window->view_center.y - 400;
    if ((*item)->y == 2)
        (*item)->item.pos.y = 384 + window->view_center.y - 400;
    if ((*item)->y == 3)
        (*item)->item.pos.y = 443 + window->view_center.y - 400;
    replace_item_second(window, item);
    replace_item_third(window, item);
    (*item)->equiped = 0;
    if ((*item)->equiped_x != -1 && (*item)->equiped_y != -1) {
        window->equip_tab[(*item)->equiped_y][(*item)->equiped_x].id = -1;
        (*item)->equiped_y = -1;
        (*item)->equiped_x = -1;
    }
    sfSprite_setPosition((*item)->item.sprite, (*item)->item.pos);
}