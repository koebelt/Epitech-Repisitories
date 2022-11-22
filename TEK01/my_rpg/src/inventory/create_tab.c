/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** create_tab
*/

#include "inventory.h"

void malloc_char(window_t *window, int i)
{
    if (i == 0 || i == 4)
        for (int a = 0; a < 1; a += 1)
            window->equip_tab[i][a].id = -1;
    else
        for (int a = 0; a < 3; a += 1)
            window->equip_tab[i][a].id = -1;
}

void malloc_lines(window_t *window, int i)
{
    if (i == 0 || i == 4)
        window->equip_tab[i] = malloc(sizeof(item_t) * 2);
    else
        window->equip_tab[i] = malloc(sizeof(item_t) * 4);
}

void create_tab(window_t *window)
{
    window->item = NULL;
    window->inventory_tab = malloc(sizeof(item_t *) * 7);
    window->inventory_tab[6] = NULL;
    for (int i = 0; i < 6; i += 1)
        window->inventory_tab[i] = malloc(sizeof(item_t) * 6);
    for (int i = 0; i < 6; i += 1)
        for (int a = 0; a < 5; a += 1)
            window->inventory_tab[i][a].id = -1;
    window->equip_tab = malloc(sizeof(item_t *) * 6);
    window->equip_tab[5] = NULL;
    for (int i = 0; i < 5; i += 1)
        malloc_lines(window, i);
    for (int i = 0; i < 5; i += 1)
        malloc_char(window, i);
}