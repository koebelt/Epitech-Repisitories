/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** bar
*/

#include "menu.h"

void sound_bar_actualise(window_t *window)
{
    if (check_btn(window, &window->menu.settings.videosettings.plus_btn)
    && window->sound_volume <= 95)
        window->sound_volume += 5;
    if (check_btn(window, &window->menu.settings.videosettings.minus_btn)
    && window->sound_volume >= 5)
        window->sound_volume -= 5;
    sfMusic_setVolume(window->dongeon.easy_music, window->music_volume);
    load_bar(&window->menu.settings.music_bar, window->music_volume);
}

void music_bar_actualise(window_t *window)
{
    if (check_btn(window, &window->menu.settings.plus_btn)
    && window->music_volume <= 95)
        window->music_volume += 5;
    if (check_btn(window, &window->menu.settings.minus_btn)
    && window->music_volume >= 5)
        window->music_volume -= 5;
    sfMusic_setVolume(window->dongeon.easy_music, window->music_volume);
    sfMusic_setVolume(window->ext.music, window->music_volume);
    sfMusic_setVolume(window->menu.music, window->music_volume);
    load_bar(&window->menu.settings.music_bar, window->music_volume);
}