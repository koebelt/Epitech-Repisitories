/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** inventory
*/

#include "inventory.h"

void init_text(text_t *text_info, char *str, sfVector2f scale, float thick)
{
    text_info->font = sfFont_createFromFile(FONT);
    text_info->text = sfText_create();
    sfText_setFont(text_info->text, text_info->font);
    sfText_setString(text_info->text, str);
    sfText_setScale(text_info->text, scale);
    sfText_setOutlineColor(text_info->text, sfBlack);
    sfText_setOutlineThickness(text_info->text, thick);
}

void place_items(window_t *window, item_t *temp)
{
    if (window->inventory.removing == 0 && window->inventory.open == 1 &&
    mouse_hover_item(temp->item.sprite, window->mouse, temp, window) == 1
    && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (temp->equiped == 0)
            equip_item(window, &temp);
        else
            replace_item(window, &temp);
    } if (temp->equiped == 1)
        check_equip(window, &temp);
}

void handle_click_inventory(window_t *window)
{
    item_t *temp = window->item;

    window->mouse.x = window->mouse.x - 120 +
    window->view_center.x - 500;
    window->mouse.y = window->mouse.y + 40 +
    window->view_center.y - 400;
    while (temp != NULL) {
        place_items(window, temp);
        temp = temp->next;
    }
    if (window->inventory.open == 1 &&
    mouse_hover(window->inventory.bin.sprite, window->mouse) == 1 &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        window->inventory.removing = 1;
        sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    }
}

void change_item(window_t *window, item_t **temp)
{
    if ((*temp)->placed == 0)
        handle_item(window, temp);
    else if ((*temp)->equiped == 0)
        replace_item(window, temp);
}

void inventory(window_t *window)
{
    item_t *temp = window->item;

    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue)
        get_rand_item(window);
    if (window->inventory.open == 1) {
        set_inv_pos(window);
        get_level(window);
        draw_inv(window);
        get_stats(window);
        while (temp != NULL) {
            change_item(window, &temp);
            temp = temp->next;
        }
        print_items(window);
        destroy_items(window);
    }
}