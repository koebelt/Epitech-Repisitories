/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** pause
*/

#include "pause.h"

void init_pause(window_t *window)
{
    init_sprite(&window->pause.play, (sprite_info_t)
    {530, 400, 1, 0, 0, 192, 48, PLAY_BTN}, window);
    init_sprite(&window->pause.settingsbtn, (sprite_info_t)
    {720, 130, 1, 0, 0, 192, 48, SETTINGS_BTN}, window);
    init_sprite(&window->pause.bg, (sprite_info_t)
    {0, 0, 1, 0, 0, 1940, 720, MAP}, window);
    init_sprite(&window->pause.table, (sprite_info_t)
    {300, 100, 0.7, 0, 0, 966, 627, TABLE_IMG}, window);
    init_sprite(&window->pause.back, (sprite_info_t)
    {330, 130, 1, 0, 0, 192, 48, BACK_BTN}, window);
    window->pause.view.size = (sfFloatRect){0, 0, window->mode.width,
    window->mode.height};
    window->pause.view.view = sfView_createFromRect(window->pause.view.size);
}

void run_pause(window_t *window)
{
    sfMusic_stop(window->ext.music);
    sfMusic_stop(window->dongeon.easy_music);
    sfRenderWindow_drawSprite(window->window, window->pause.bg.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->pause.table.sprite,
    NULL);
    sfRenderWindow_drawSprite(window->window, window->pause.back.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->pause.play.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->pause.settingsbtn.sprite,
    NULL);
    sfRenderWindow_setView(window->window, window->pause.view.view);
}

void check_pause(window_t *window)
{
    if (check_btn(window, &window->pause.play) && window->stackg == GAME_ID)
        window->index = GAME_ID;
    if (check_btn(window, &window->pause.play) && window->stackg ==
    DONGEONS_ID)
        window->index = DONGEONS_ID;
    if (check_btn(window, &window->pause.settingsbtn)) {
        window->stack = window->index;
        window->index = SETTINGS_ID;
    }
    if (check_btn(window, &window->pause.back))
        sfRenderWindow_close(window->window);
}

void event_pause(window_t *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        check_pause(window);
}