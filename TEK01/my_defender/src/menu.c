/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** menu
*/

#include "../include/include.h"

int menu_mouse_event(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect start_box = sfSprite_getGlobalBounds(menu->play.sprite);
    char *music_path[3] = {"assets/music/game_1.ogg", "assets/music/game_2.ogg",
    "assets/music/game_3.ogg"};

    sfSound_play(window->click);
    if (sfFloatRect_contains(&start_box, mouse.x, mouse.y)) {
        window->index = 1;
        music_set_audio(&window->game.music, music_path[rand() % (3)],
        window->music_volume);
    } else
        menu_mouse_event2(menu, mouse, window);
    return (0);
}

int analyse_menu_events(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed)
        menu_mouse_event(&window->menu, window->event.mouseButton, window);
}

void menu4(window_t *window)
{
    sfRenderWindow_drawSprite(window->window, window->menu.sound_on.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.sound_off.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.exit.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.setting_menu.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.setting_close.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.setting_plus1.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window,
    window->menu.setting_minus1.sprite, sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.setting_plus2.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window,
    window->menu.setting_minus2.sprite, sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.music_bar.sprite,
    sfFalse);
}

void menu(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_menu_events(window);
    }
    sfMusic_stop(window->game.music);
    if (!sfMusic_getStatus(window->menu.music))
        sfMusic_play(window->menu.music);
    menu2(window);
    menu3(window);
    menu4(window);
    sfRenderWindow_drawSprite(window->window, window->menu.sound_bar.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.shop_button.sprite,
    sfFalse);
    sfRenderWindow_drawSprite(window->window, window->menu.how_to_play.sprite,
    sfFalse);
    sfMusic_setVolume(window->menu.music, window->music_volume);
    sfMusic_setVolume(window->game.music, window->music_volume);
    sfSound_setVolume(window->click, window->sound_volume);
    sfSound_setVolume(window->win_menu.win_sound, window->sound_volume);
    sfSound_setVolume(window->loose_menu.loose_sound, window->sound_volume);
}