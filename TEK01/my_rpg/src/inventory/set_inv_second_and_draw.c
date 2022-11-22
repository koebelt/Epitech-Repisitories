/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** set_inv_second_and_draw
*/

#include "inventory.h"

void set_inv_pos_sixth(window_t *window)
{
    window->inventory.points.pos.x = 490 +
    window->view_center.x - 500;
    window->inventory.points.pos.y = 390 +
    window->view_center.y - 400;
    window->inventory.points_nbr.pos.x = 510 +
    window->view_center.x - 500;
    window->inventory.points_nbr.pos.y = 405 +
    window->view_center.y - 400;
    sfText_setPosition(window->inventory.points.text,
    window->inventory.points.pos);
    sfText_setPosition(window->inventory.points_nbr.text,
    window->inventory.points_nbr.pos);
}

void draw_inv_third(window_t *window)
{
    sfRenderWindow_drawText(window->window,
    window->inventory.points_nbr.text, NULL);
}

void draw_inv_second(window_t *window)
{
    sfRenderWindow_drawText(window->window,
    window->inventory.stat_attack_speed_nbr.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.stat_speed_nbr.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.stat_armor_nbr.text, NULL);
    sfRenderWindow_drawText(window->window, window->inventory.exp.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.slash.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.level.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.level_nbr.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.exp_nbr.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.exp_next_lvl.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.points.text, NULL);
    draw_inv_third(window);
}

void draw_inv(window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->inventory.inventory.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->inventory.bin.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->inventory.bin_temp.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->inventory.select.sprite, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.stat_damage.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.stat_attack_speed.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.stat_speed.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.stat_armor.text, NULL);
    sfRenderWindow_drawText(window->window,
    window->inventory.stat_damage_nbr.text, NULL);
    draw_inv_second(window);
}