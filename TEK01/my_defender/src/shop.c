/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** shop
*/

#include "../include/include.h"

int calc_tower_sprite(shop_item_t *tower, sfMouseButtonEvent mouse, int lvl,
window_t *window)
{
    sfFloatRect tower_bt = sfSprite_getGlobalBounds(tower->icon.sprite);

    if (sfFloatRect_contains(&tower_bt, mouse.x, mouse.y) && window->player.gold
    >= tower->price[lvl] && lvl < tower->levels) {
        lvl++;
        window->player.gold -= tower->price[lvl - 1];
    }
    return (lvl);
}

int shop_mouse_event(shop_t *shop, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect shop_button_close =
    sfSprite_getGlobalBounds(shop->close_bt.sprite);

    sfSound_play(window->click);
    if (sfFloatRect_contains(&shop_button_close, mouse.x, mouse.y)) {
        window->index = 0;
    }
    window->player.hdv_lvl = calc_tower_sprite(&shop->hdv_bt, mouse,
    window->player.hdv_lvl, window);
    window->player.archer_lvl = calc_tower_sprite(&shop->archer_t_bt,
    mouse, window->player.archer_lvl, window);
    window->player.wizard_lvl = calc_tower_sprite(&shop->wizard_t_bt,
    mouse, window->player.wizard_lvl, window);
    window->player.inferno_lvl = calc_tower_sprite(&shop->inferno_t_bt,
    mouse, window->player.inferno_lvl, window);
    window->player.eagle_lvl = calc_tower_sprite(&shop->eagle_t_bt, mouse,
    window->player.eagle_lvl, window);
    window->player.tesla_lvl = calc_tower_sprite(&shop->tesla_t_bt, mouse,
    window->player.tesla_lvl, window);
    return (0);
}

int analyse_level_shop(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed)
        shop_mouse_event(&window->shop, window->event.mouseButton, window);
}

void display_item(window_t *window, shop_item_t *item, int lvl)
{
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &item->icon);
    if (item->levels == lvl)
        sfSprite_setColor(item->icon.sprite, sfColor_fromRGB(100, 100, 100));
    item->icon.rect.left = lvl < item->levels ? item->icon.rect.width * lvl :
    item->icon.rect.width * (lvl - 1);
    sfSprite_setTextureRect(item->icon.sprite, item->icon.rect);
    sfRenderWindow_drawSprite(window->window, item->icon.sprite, sfFalse);
}

void shop(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event))
        analyse_level_shop(window);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->shop.close_bt);
    sfRenderWindow_drawSprite(window->window, window->shop.background.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->shop.menu.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->shop.close_bt.sprite,
    sfFalse);
    display_item(window, &window->shop.hdv_bt, window->player.hdv_lvl);
    display_item(window, &window->shop.archer_t_bt, window->player.archer_lvl);
    display_item(window, &window->shop.wizard_t_bt, window->player.wizard_lvl);
    display_item(window, &window->shop.inferno_t_bt,
    window->player.inferno_lvl);
    display_item(window, &window->shop.eagle_t_bt, window->player.eagle_lvl);
    display_item(window, &window->shop.tesla_t_bt, window->player.tesla_lvl);
    sfText_setString(window->shop.gold.text,
    my_int_to_str(window->player.gold));
    sfRenderWindow_drawText(window->window, window->shop.gold.text, sfFalse);
}