/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** choose.c
*/

#include "include.h"

void disp_bottles(choose_bottles_t *bottles, sfVector2i mouse_pos,
    sfRenderWindow **window)
{
    disp_wwhine(&bottles->bottle0, mouse_pos, window);
    disp_rwhine(&bottles->bottle1, mouse_pos, window);
    disp_wiskey(&bottles->bottle2, mouse_pos, window);
    disp_bwhine(&bottles->bottle3, mouse_pos, window);
    disp_gwhine(&bottles->bottle4, mouse_pos, window);
    disp_champagne(&bottles->bottle5, mouse_pos, window);
}


void choose_events(window_obj_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        change_index(window, analyse_choose_events(window));
    }
}

void choose_play(window_obj_t *window)
{
    choose_events(window);

    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    if (window->choose.crosshair.shooting)
        window->choose.hand.shooting = 3;
    disp_bottles(&window->choose.bottles, mouse, &window->window);
    disp_high_score(window);
    anim_hunter(&window->choose.hunter, &window->choose.anim_clock, mouse,
    &window->window);
    calc_hand(&window->choose.hand, mouse, &window->window,
    &window->choose.hand_clock);
    move_crosshair(&window->choose.crosshair, mouse,& window->window);

}
