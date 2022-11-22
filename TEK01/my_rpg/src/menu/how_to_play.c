/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** how_to_play
*/

#include "menu.h"

void init_howtoplay(window_t *window)
{
    init_sprite(&window->menu.htp.how_to_play, (sprite_info_t)
    {0, 0, 1, 0, 0, 1240, 720, HOW_TO_PLAY}, window);
    init_sprite(&window->menu.htp.back, (sprite_info_t)
    {10, 650, 1, 0, 0, 192, 48, BACK_BTN}, window);
}

void run_howtoplay(window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->menu.htp.how_to_play.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->menu.htp.back.sprite, NULL);
}

void check_htp(window_t *window)
{
    if (check_btn(window, &window->menu.htp.back))
        window->index = MENU_ID;
}

void event_howtoplay(window_t *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        check_htp(window);
}