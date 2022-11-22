/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** shop2
*/

#include "../include/include.h"

void init_item(shop_item_t *item, int *prices, int level, sprite_info_t info)
{
    item->icon = init_sprite(info);
    item->levels = level;
    item->price = malloc(sizeof(int) * level);
    for (int i = 0; i < level; ++i)
        item->price[i] = prices[i];
}

void init_shop2(shop_t *shop, window_t *window)
{
    init_item(&shop->hdv_bt, (int[10]){0, 3, 6, 9, 12, 16, 18, 20, 22, 25}, 10,
    (sprite_info_t){855, 250, 1.1, 1.1, 0, 171, 170, 171, HDV_BT});
    init_item(&shop->archer_t_bt, (int[12]){0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7},
    12, (sprite_info_t){650, 450, 1.1, 1.1, 0, 171, 170, 171, ARCHER_T_BT});
    init_item(&shop->wizard_t_bt, (int[9]){0, 2, 4, 6, 8, 10, 13, 16, 20}, 9,
    (sprite_info_t){1060, 450, 1.1, 1.1, 0, 171, 170, 171, WIZARD_T_BT});
    init_item(&shop->inferno_t_bt, (int[7]){5, 8, 10, 14, 18, 20, 25}, 7,
    (sprite_info_t){445, 650, 1.1, 1.1, 0, 0, 170, 171, INFERNO_T_BT});
    init_item(&shop->eagle_t_bt, (int[4]){6, 12, 20, 36}, 4,
    (sprite_info_t){855, 650, 1.1, 1.1, 0, 0, 170, 171, EAGLE_T_BT});
    init_item(&shop->tesla_t_bt, (int[8]){3, 5, 7, 9, 11, 13, 15, 20}, 8,
    (sprite_info_t){1265, 650, 1.1, 1.1, 0, 0, 170, 171, TESLA_T_BT});
}

void init_shop(shop_t *shop, window_t *window)
{
    shop->background = init_sprite((sprite_info_t){0, 0, 1, 1, 0, 0, 1080,
    1920, BG});
    shop->menu = init_sprite((sprite_info_t){310, 12, 1, 1, 0, 0, 1019, 1277,
    SHOP_M});
    shop->close_bt = init_sprite((sprite_info_t){310, 12, 1, 1, 0, 0, 1019,
    1277, SHOP_M});
    shop->close_bt = init_sprite((sprite_info_t){1480, 5, 1, 1, 0, 0, 104,
    104, "assets/menu/setting_cl.png"});
    init_text(&shop->gold, 60, "0", (sfVector2f){400, 900});
    sfText_setOutlineThickness(shop->gold.text, 2);
    sfText_setOutlineColor(shop->gold.text, sfBlack);
    init_shop2(shop, window);
}