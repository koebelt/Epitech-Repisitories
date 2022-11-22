/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** equip_items
*/

#include "inventory.h"

void arms(window_t *window, item_t **item)
{
    if (window->equip_tab[1][0].id == -1)
        equip(window, item, 1, 0);
    else if (window->equip_tab[1][2].id == -1)
        equip(window, item, 1, 2);
}

void rings(window_t *window, item_t **item)
{
    if (window->equip_tab[2][0].id == -1)
        equip(window, item, 2, 0);
    else if (window->equip_tab[2][2].id == -1)
        equip(window, item, 2, 2);
}

void books(window_t *window, item_t **item)
{
    if (window->equip_tab[3][0].id == -1)
        equip(window, item, 3, 0);
    else if (window->equip_tab[3][2].id == -1)
        equip(window, item, 3, 2);
}

void equip_item_second(window_t *window, item_t **item)
{
    if (my_strcmp((*item)->stats.type, "rune") == 1 &&
    window->equip_tab[4][0].id == -1)
        equip(window, item, 4, 0);
    if (my_strcmp((*item)->stats.type, "arms") == 1)
        arms(window, item);
    if (my_strcmp((*item)->stats.type, "book") == 1)
        books(window, item);
    if (my_strcmp((*item)->stats.type, "ring") == 1)
        rings(window, item);
}

void equip_item(window_t *window, item_t **item)
{
    if (my_strcmp((*item)->stats.type, "head") == 1 &&
    window->equip_tab[0][0].id == -1)
        equip(window, item, 0, 0);
    if (my_strcmp((*item)->stats.type, "feet") == 1 &&
    window->equip_tab[3][1].id == -1)
        equip(window, item, 3, 1);
    if (my_strcmp((*item)->stats.type, "armor") == 1 &&
    window->equip_tab[1][1].id == -1)
        equip(window, item, 1, 1);
    if (my_strcmp((*item)->stats.type, "legs") == 1 &&
    window->equip_tab[2][1].id == -1)
        equip(window, item, 2, 1);
    equip_item_second(window, item);
}