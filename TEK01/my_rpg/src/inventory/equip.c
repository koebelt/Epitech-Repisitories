/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** equip
*/

#include "inventory.h"

void equip(window_t *window, item_t **item, int i, int a) {
    window->equip_tab[i][a].id = 1;
    (*item)->equiped = 1;
    (*item)->equiped_y = i;
    (*item)->equiped_x = a;
}

void check_equip_first(window_t *window, item_t **item, int i)
{
    if (i == 0)
        (*item)->item.pos.y = 289 + window->view_center.y - 400;
    if (i == 4)
        (*item)->item.pos.y = 544 + window->view_center.y - 400;
    (*item)->item.pos.x = 170 + window->view_center.x - 500;
}

void check_equip_y(window_t *window, item_t **item, int i)
{
    if (i == 1)
        (*item)->item.pos.y = 355 + window->view_center.y - 400;
    if (i == 2)
        (*item)->item.pos.y = 420 + window->view_center.y - 400;
    if (i == 3)
        (*item)->item.pos.y = 480 + window->view_center.y - 400;
}

void check_equip_x(window_t *window, item_t **item, int a)
{
    if (a == 0)
        (*item)->item.pos.x = 110 + window->view_center.x - 500;
    if (a == 1)
        (*item)->item.pos.x = 170 + window->view_center.x - 500;
    if (a == 2)
        (*item)->item.pos.x = 227 + window->view_center.x - 500;
}

void check_equip(window_t *window, item_t **item)
{
    int i = (*item)->equiped_y;
    int a = (*item)->equiped_x;

    if (i == 0 || i == 4)
        check_equip_first(window, item, i);
    else {
        check_equip_y(window, item, i);
        check_equip_x(window, item, a);
    }
    sfSprite_setPosition((*item)->item.sprite, (*item)->item.pos);
}