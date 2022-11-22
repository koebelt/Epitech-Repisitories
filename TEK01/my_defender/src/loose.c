/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** loose
*/

#include "../include/include.h"

void init_loose_menu(loose_menu_t *loose_menu, window_t *window)
{
    loose_menu->background = init_sprite((sprite_info_t){0, 0, 1, 1, 0, 0,
    1080, 1920, "assets/menu/bg.png"});
    loose_menu->window = init_sprite((sprite_info_t){650, 100, 1, 1, 0, 0,
    0, 0, "assets/game_ui/failed_menu.png"});
    loose_menu->menu_button = init_sprite((sprite_info_t){610, 750, 1, 1, 0, 0,
    0, 0, "assets/menu/button_left.png"});
    loose_menu->retry = init_sprite((sprite_info_t){1160, 750, 1, 1, 0, 0, 0,
    0, "assets/game_ui/button_restart.png"});
    loose_menu->played = 0;

    sound_set_audio(&loose_menu->loose_sound, "assets/music/loose.ogg",
    window->sound_volume);
}

int loose_menu_mouse_event(loose_menu_t *loose_menu, sfMouseButtonEvent mouse,
window_t *window)
{
    sfFloatRect return_box =
    sfSprite_getGlobalBounds(loose_menu->menu_button.sprite);
    sfFloatRect next_box = sfSprite_getGlobalBounds(loose_menu->retry.sprite);

    sfSound_play(window->click);
    if (sfFloatRect_contains(&return_box, mouse.x, mouse.y)) {
        window->index = 0;
        loose_menu->played = 0;
    }
    if (sfFloatRect_contains(&next_box, mouse.x, mouse.y)) {
        window->level = window->level_select.levels[window->level.level - 1];
        init_game(&window->game, &window->clock, window);
        window->index = 2;
        loose_menu->played = 0;
    }
}

int analyse_loose_menu_events(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed)
        loose_menu_mouse_event(&window->loose_menu, window->event.mouseButton,
        window);
}

void loose_menu(window_t *window)
{
    sfMusic_stop(window->game.music);
    if (!window->loose_menu.played) {
        sfSound_play(window->loose_menu.loose_sound);
        window->loose_menu.played = 1;
    }
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_loose_menu_events(window);
    }
    button_hover_color_animation(window->mouse, &window->loose_menu.retry);
    button_hover_color_animation(window->mouse,
    &window->loose_menu.menu_button);
    sfRenderWindow_drawSprite(window->window,
    window->loose_menu.background.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->loose_menu.window.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->loose_menu.menu_button.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->loose_menu.retry.sprite, NULL);

}