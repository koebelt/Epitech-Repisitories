/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** event_inventory
*/

#include "inventory.h"

void show_inventory(window_t *window)
{
    window->inventory.inventory.pos.x = window->view_center.x - 480;
    window->inventory.inventory.pos.y = window->view_center.y - 450;
    window->inventory.bin.pos.x = window->view_center.x + 50;
    window->inventory.bin.pos.y = window->view_center.y - 330;
    window->inventory.select.pos.x = window->view_center.x - 30;
    window->inventory.select.pos.y = window->view_center.y - 330;
    sfSprite_setPosition(window->inventory.inventory.sprite,
    window->inventory.inventory.pos);
    sfSprite_setPosition(window->inventory.bin.sprite,
    window->inventory.bin.pos);
    sfSprite_setPosition(window->inventory.select.sprite,
    window->inventory.select.pos);
    if (window->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyI)) {
        if (window->inventory.open == 0)
            window->inventory.open = 1;
        else
            window->inventory.open = 0;
    }
}

void change_mouse(window_t *window)
{
    if (window->index == 3) {
        window->mouse.x = window->mouse.x - 120 +
        window->view_center.x - 500;
        window->mouse.y = window->mouse.y + 40 +
        window->view_center.y - 400;
        window->mouse.x -= 240;
        window->mouse.y += 80;
    } else {
        window->mouse.x = window->mouse.x - 120 -
        (window->ext.player.sprite.pos.x - 500);
        window->mouse.y = window->mouse.y + 40 -
        (window->ext.player.sprite.pos.y - 400);
    }
}

void assign_points(window_t *window)
{
    change_mouse(window);
    if (window->mouse.y > 410 && window->mouse.y < 430 &&
    window->mouse.x > 355 && window->mouse.x < 370) {
        window->inventory.damage_points += 1;
        window->inventory.points_int -= 1;
    } if (window->mouse.y > 445 && window->mouse.y < 465 &&
    window->mouse.x > 355 && window->mouse.x < 370) {
        window->inventory.attack_speed_points += 1;
        window->inventory.points_int -= 1;
    } if (window->mouse.y > 480 && window->mouse.y < 500 &&
    window->mouse.x > 355 && window->mouse.x < 370) {
        window->inventory.speed_points += 1;
        window->inventory.points_int -= 1;
    } if (window->mouse.y > 510 && window->mouse.y < 530 &&
    window->mouse.x > 355 && window->mouse.x < 370) {
        window->inventory.armor_points += 1;
        window->inventory.points_int -= 1;
    }
}

void get_points(window_t *window)
{
    if (window->inventory.points_int > 0 &&
    window->event.type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        assign_points(window);
    sfText_setString(window->inventory.points_nbr.text,
    int_to_str(window->inventory.points_int));
}