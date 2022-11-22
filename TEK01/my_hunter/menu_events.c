/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** menu_events.c
*/

#include "include.h"

int menu_mouse_click(sfMouseButtonEvent mouse_pos, menu_obj_t *menu)
{
    if (mouse_pos.x > menu->start.sprite.pos.x && mouse_pos.x <
    (menu->start.sprite.pos.x + menu->start.sprite.size_text.x *
    menu->start.sprite.scale.x) && mouse_pos.y > menu->start.sprite.pos.y &&
    mouse_pos.y < (menu->start.sprite.pos.y + menu->start.sprite.size_text.x *
    menu->start.sprite.scale.y))
        return (1);
    if (mouse_pos.x > menu->choose.sprite.pos.x && mouse_pos.x <
    menu->choose.sprite.pos.x + (menu->choose.sprite.size_text.x *
    menu->choose.sprite.scale.x) && mouse_pos.y > menu->choose.sprite.pos.y &&
    mouse_pos.y < (menu->choose.sprite.pos.y + menu->choose.sprite.size_text.x *
    menu->choose.sprite.scale.y))
        return (2);
    if (mouse_pos.x > menu->restart.sprite.pos.x && mouse_pos.x <
    menu->restart.sprite.pos.x + (menu->restart.sprite.size_text.x *
    menu->restart.sprite.scale.x) && mouse_pos.y > menu->restart.sprite.pos.y &&
    mouse_pos.y < (menu->restart.sprite.pos.y + menu->restart.sprite.size_text.x
    * menu->restart.sprite.scale.y))
        return (3);
    return (0);
}

int analyse_menu_events(window_obj_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed) {
        sfSound_play(window->game.gun);
        window->menu.crosshair.shooting = 2;
        return(menu_mouse_click(window->event.mouseButton, &window->menu));
    }
    return (0);
}

void menu_events(window_obj_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        if (analyse_menu_events(window) == 1) {
            window->index = 1;
            window->game.score = 0;
            window->game.health = 11;
            sfClock_restart(window->game.mvmnt_clock);
            sfSound_play(window->game.breaking_bottle);
        }
        if (analyse_menu_events(window) == 2) {
            window->index = 2;
            sfSound_play(window->game.breaking_bottle);
        }
        if (analyse_menu_events(window) == 3)
            window->high_score = 0;
    }
}
