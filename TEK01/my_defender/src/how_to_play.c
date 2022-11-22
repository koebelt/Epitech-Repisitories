/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** how_to_play
*/

#include "../include/include.h"

void init_how_to_play(howtpl_t *how_to_play, window_t *window)
{
    how_to_play->background = init_sprite((sprite_info_t){0, -30, 1, 1, 0, 0,
    1080, 1920, "assets/menu/how_to_play_img.png"});
    how_to_play->close_bt = init_sprite((sprite_info_t){1800, 20, 1, 1, 0, 0,
    104, 104, "assets/menu/setting_cl.png"});
}

int howtpl_mouse_event(howtpl_t *how_to_play, sfMouseButtonEvent mouse,
window_t *window)
{
    sfFloatRect howtpl_button_close =
    sfSprite_getGlobalBounds(how_to_play->close_bt.sprite);

    sfSound_play(window->click);
    if (sfFloatRect_contains(&howtpl_button_close, mouse.x, mouse.y))
        window->index = 0;
    return (0);
}

int analyse_level_howtpl(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed)
        howtpl_mouse_event(&window->how_to_play,
        window->event.mouseButton, window);
}

void how_to_play(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_level_howtpl(window);
    }
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &window->how_to_play.close_bt);
    sfRenderWindow_drawSprite(window->window,
    window->how_to_play.background.sprite, sfFalse);
    sfRenderWindow_drawSprite(window->window,
    window->how_to_play.close_bt.sprite, sfFalse);
}