/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** event_videostg
*/

#include "menu.h"

void button_status_sound(window_t *window)
{
    if (check_btn(window, &window->menu.settings.videosettings.sound) &&
    window->menu.settings.videosettings.sound_status == 0) {
        change_texture(&window->menu.settings.videosettings.sound, MUSIC_BTN);
        window->menu.settings.videosettings.sound_status = 1;
    } else if (check_btn(window, &window->menu.settings.videosettings.sound) &&
    window->menu.settings.videosettings.sound_status == 1) {
        change_texture(&window->menu.settings.videosettings.sound,
        MUSIC_OFF_BTN);
        window->menu.settings.videosettings.sound_status = 0;
    }
}

void check_settingsstg(window_t *window)
{
    if (check_btn(window, &window->menu.settings.videosettings.music_title))
        window->index = SETTINGS_ID;
    if (check_btn(window, &window->menu.settings.videosettings.back))
        window->index = MENU_ID;
    button_status_sound(window);
    sound_bar_actualise(window);
}

void event_videostg(window_t *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        check_settingsstg(window);
}