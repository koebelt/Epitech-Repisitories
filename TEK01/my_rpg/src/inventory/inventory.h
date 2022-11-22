/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** inventory
*/

#include "../../include/include.h"
#include "../items/items.h"

#ifndef INVENTORY_H_
#define INVENTORY_H_

#define INVENTORY_TEXT "assets/inventory/inventory.png"
#define BIN "assets/inventory/bin.png"
#define SELECT "assets/inventory/select.png"
#define BOARD "assets/inventory/board.png"
#define FONT "assets/font/LEMONMILK-Regular.otf"

void inventory(window_t *window);
void init_inventory(window_t *window);
void show_inventory(window_t *window);
void create_tab(window_t *window);
void handle_click_inventory(window_t *window);
void equip_item(window_t *window, item_t **item);
void check_equip(window_t *window, item_t **item);
void get_points(window_t *window);
void equip(window_t *window, item_t **item, int i, int a);
void init_text(text_t *text_info, char *str, sfVector2f scale, float thick);
void set_inv_pos(window_t *window);
void set_inv_pos_sixth(window_t *window);
void draw_inv(window_t *window);
void get_level(window_t * window);
void get_stats(window_t *window);
void create_tab(window_t *window);

#endif /* !INVENTORY_H_ */
