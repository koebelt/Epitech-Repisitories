/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** menu
*/

#include "menu.h"

void init_menu(window_t *window)
{
    init_sprite(&window->menu.play, (sprite_info_t)
    {530, 600, 1, 0, 0, 192, 48, PLAY_BTN}, window);
    init_sprite(&window->menu.settingsbtn, (sprite_info_t)
    {1000, 650, 1, 0, 0, 192, 48, SETTINGS_BTN}, window);
    init_sprite(&window->menu.bg, (sprite_info_t)
    {0, 0, 1, 0, 0, 1940, 720, MAP}, window);
    init_sprite(&window->menu.htpbtn, (sprite_info_t)
    {1050, 20, 0.3, 0, 0, 500, 200, HTP_BTN}, window);
    music_set_audio(&window->menu.music, "assets/musics/menu.ogg",
    window->music_volume);
}

void run_menu(window_t *window)
{
    sfMusic_stop(window->ext.music);
    sfMusic_stop(window->dongeon.easy_music);
    if (!sfMusic_getStatus(window->menu.music))
        sfMusic_play(window->menu.music);
    sfRenderWindow_drawSprite(window->window, window->menu.bg.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->menu.play.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->menu.htpbtn.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->menu.settingsbtn.sprite, NULL);
}