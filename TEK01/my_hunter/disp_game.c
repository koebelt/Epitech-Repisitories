/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** disp_game.c
*/

#include "include.h"

void disp_score(window_obj_t *window)
{
    sfRenderWindow_drawText(window->window, window->game.text, NULL);
    sfText_setString(window->game.text, my_strcat("SCORE: ",
    my_int_to_str(window->game.score)));
}

void disp_game(window_obj_t *window, sfVector2i mouse)
{
    sfMusic_stop(window->menu.music);
    if (!sfMusic_getStatus(window->game.music))
        sfMusic_play(window->game.music);

    calc_one_bottle(&window->game.bottle, &window->window,
    window->game.mvmnt_clock);
    anim_hunter(&window->game.hunter, &window->game.anim_clock, mouse,
    &window-> window);
    calc_hand(&window->game.hand, mouse, &window->window,
    &window->game.hand_clock);
    disp_score(window);
    disp_health(&window->game, &window->window);
    move_crosshair(&window->game.crosshair, mouse, &window->window);
}
