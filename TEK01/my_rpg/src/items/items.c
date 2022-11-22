/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** items
*/

#include "items.h"

void print_items(window_t *window)
{
    item_t *temp = window->item;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(window->window, temp->item.sprite, NULL);
        temp = temp->next;
    }
}

void get_place(window_t *window, item_t **item, int a, int i)
{
    if (window->inventory_tab[i][a].id == -1) {
        window->inventory_tab[i][a].id = 1;
        (*item)->x = a;
        (*item)->y = i;
        (*item)->placed = 1;
    }
}

void handle_item(window_t *window, item_t **item)
{
    for (int i = 0; i < 6; i += 1)
        for (int a = 0; a < 5 && (*item)->placed == 0; a += 1)
            get_place(window, item, a, i);
}