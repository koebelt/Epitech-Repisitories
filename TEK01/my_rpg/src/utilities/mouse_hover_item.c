/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** mouse_hover_item
*/

#include "../../include/include.h"

void mouse_hover_item_set_pos_start(window_t *window)
{
    window->inventory.board.pos.x = window->mouse.x + 10;
    window->inventory.board.pos.y = window->mouse.y - 30;
    window->inventory.damage.pos.x = window->mouse.x + 27;
    window->inventory.damage.pos.y = window->mouse.y + 30;
    window->inventory.attack_speed.pos.x = window->mouse.x + 27;
    window->inventory.attack_speed.pos.y = window->mouse.y + 55;
    window->inventory.speed.pos.x = window->mouse.x + 27;
    window->inventory.speed.pos.y = window->mouse.y + 80;
    window->inventory.armor.pos.x = window->mouse.x + 27;
    window->inventory.armor.pos.y = window->mouse.y + 105;
    window->inventory.damage_nbr.pos.x = window->mouse.x + 200;
    window->inventory.damage_nbr.pos.y = window->mouse.y + 30;
    window->inventory.attack_speed_nbr.pos.x = window->mouse.x + 200;
    window->inventory.attack_speed_nbr.pos.y = window->mouse.y + 55;
    window->inventory.speed_nbr.pos.x = window->mouse.x + 200;
    window->inventory.speed_nbr.pos.y = window->mouse.y + 80;
    window->inventory.armor_nbr.pos.x = window->mouse.x + 200;
    window->inventory.armor_nbr.pos.y = window->mouse.y + 105;
}

void mouse_hover_item_set_pos(window_t *window)
{
    sfSprite_setPosition(window->inventory.board.sprite,
    window->inventory.board.pos);
    sfText_setPosition(window->inventory.damage.text,
    window->inventory.damage.pos);
    sfText_setPosition(window->inventory.attack_speed.text,
    window->inventory.attack_speed.pos);
    sfText_setPosition(window->inventory.speed.text,
    window->inventory.speed.pos);
    sfText_setPosition(window->inventory.armor.text,
    window->inventory.armor.pos);
    sfText_setPosition(window->inventory.damage_nbr.text,
    window->inventory.damage_nbr.pos);
    sfText_setPosition(window->inventory.attack_speed_nbr.text,
    window->inventory.attack_speed_nbr.pos);
    sfText_setPosition(window->inventory.speed_nbr.text,
    window->inventory.speed_nbr.pos);
    sfText_setPosition(window->inventory.armor_nbr.text,
    window->inventory.armor_nbr.pos);
}

void mouse_hover_draw_text_and_sprites(window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->inventory.board.sprite, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.damage.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.attack_speed.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.speed.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.armor.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.damage_nbr.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.attack_speed_nbr.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.speed_nbr.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.armor_nbr.text, NULL);
}

void start_of_mouse_hover_item(window_t *window,  item_t *item)
{
    mouse_hover_item_set_pos_start(window);
    mouse_hover_item_set_pos(window);
    sfText_setString(window->inventory.damage_nbr.text,
    int_to_str(item->stats.damage));
    sfText_setString(window->inventory.attack_speed_nbr.text,
    int_to_str(item->stats.attack_speed));
    sfText_setString(window->inventory.speed_nbr.text,
    int_to_str(item->stats.speed));
    sfText_setString(window->inventory.armor_nbr.text,
    int_to_str(item->stats.armor));
}

int mouse_hover_item(sfSprite *sprite_button, sfVector2i mouse, item_t *item,
window_t *window)
{
    sfFloatRect mouse_rect = sfSprite_getGlobalBounds(sprite_button);
    sfColor color;
    int num = 0;

    start_of_mouse_hover_item(window, item);
    if (sfFloatRect_contains(&mouse_rect, mouse.x, mouse.y)) {
        color = sfColor_fromRGBA(255, 255, 255, 150);
        num += 1;
        mouse_hover_draw_text_and_sprites(window);
    } else
        color = sfColor_fromRGBA(255, 255, 255, 255);
    sfSprite_setColor(sprite_button, color);
    return (num);
}