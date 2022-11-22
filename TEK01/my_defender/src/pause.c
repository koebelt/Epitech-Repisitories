/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** pause
*/

#include "../include/include.h"

void init_pause(pause_t *pause)
{
    pause->background = init_sprite((sprite_info_t){0, 0, 1, 1, 0, 0, 1080,
    1920, "assets/menu/bg.png"});
    pause->menu = init_sprite((sprite_info_t){300, 100, 1.5, 1.5, 0, 0, 0, 0,
    "assets/menu/pause_menu.png"});
    pause->return_to_menu = init_sprite((sprite_info_t){375, 750, 1, 1, 0, 0,
    0, 0, "assets/menu/button_left.png"});
    pause->continue_play = init_sprite((sprite_info_t){1390, 750, 1, 1, 0, 0,
    176, 176, "assets/menu/play_bt_square.png"});
}

int pause_mouse_event(pause_t *pause, sfMouseButtonEvent mouse,
window_t *window)
{
    sfFloatRect return_box =
    sfSprite_getGlobalBounds(pause->return_to_menu.sprite);
    sfFloatRect continue_box =
    sfSprite_getGlobalBounds(pause->continue_play.sprite);

    sfSound_play(window->click);
    if (sfFloatRect_contains(&return_box, mouse.x, mouse.y))
        window->index = 0;
    if (sfFloatRect_contains(&continue_box, mouse.x, mouse.y))
        window->index = 2;
}

int analyse_pause_events(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed)
        pause_mouse_event(&window->pause, window->event.mouseButton, window);
}

void pause_game(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_pause_events(window);
    }
    button_hover_color_animation(window->mouse, &window->pause.continue_play);
    button_hover_color_animation(window->mouse, &window->pause.return_to_menu);
    sfRenderWindow_drawSprite(window->window, window->pause.background.sprite,
    NULL);
    sfRenderWindow_drawSprite(window->window, window->pause.menu.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->pause.return_to_menu.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->pause.continue_play.sprite, NULL);
}