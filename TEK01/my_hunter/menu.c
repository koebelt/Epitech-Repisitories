/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** menu.c
*/

#include "include.h"

void disp_high_score(window_obj_t *window)
{
    sfRenderWindow_drawText(window->window, window->menu.text, NULL);
    sfText_setString(window->menu.text, my_strcat("HIGH SCORE: ",
    my_int_to_str(window->high_score)));

}
void menu_play(window_obj_t *window)
{
    menu_events(window);
    sfMusic_stop(window->game.music);
    if (!sfMusic_getStatus(window->menu.music))
        sfMusic_play(window->menu.music);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    mouse.x = mouse.x <= 10 ? 10 : mouse.x;
    if (window->menu.crosshair.shooting)
        window->menu.hand.shooting = 3;
    disp_high_score(window);
    anim_reset(&window->menu.restart, mouse, &window->window);
    anim_start(&window->menu.start, mouse, &window->window);
    anim_choose(&window->menu.choose, mouse, &window->window);
    anim_hunter(&window->menu.hunter, &window->menu.anim_clock, mouse,
    &window->window);
    calc_hand(&window->menu.hand, mouse, &window->window,
    &window->menu.hand_clock);
    move_crosshair(&window->menu.crosshair, mouse,& window->window);

}
