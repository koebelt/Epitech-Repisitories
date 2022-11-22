/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** event_menu
*/

#include "menu.h"

int check_start(window_t *window)
{
    if (check_btn(window, &window->menu.play))
        window->index = GAME_ID;
    if (check_btn(window, &window->menu.settingsbtn)) {
        window->stack = window->index;
        window->index = SETTINGS_ID;
    }
    if (check_btn(window, &window->menu.htpbtn))
        window->index = HTP_ID;
    return (0);
}

void event_menu(window_t *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        check_start(window);
}

void button_status_music(window_t *window)
{
    if (check_btn(window, &window->menu.settings.music) &&
    window->menu.settings.music_status == 0) {
        change_texture(&window->menu.settings.music, MUSIC_BTN);
        window->menu.settings.music_status = 1;
    } else if (check_btn(window, &window->menu.settings.music) &&
    window->menu.settings.music_status == 1) {
        change_texture(&window->menu.settings.music, MUSIC_OFF_BTN);
        window->menu.settings.music_status = 0;
    }
}

int check_settings(window_t *window)
{
    if (check_btn(window, &window->menu.settings.back))
        window->index = window->stack;
    if (check_btn(window, &window->menu.settings.display_title))
        window->index = VIDEO_ID;
    button_status_music(window);
    music_bar_actualise(window);
    return (0);
}

void event_settings(window_t *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        check_settings(window);
}