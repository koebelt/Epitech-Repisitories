/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** level_selection
*/

#include "../include/include.h"

void level_mouse_event(level_select_t *levels, sfMouseButtonEvent mouse,
window_t *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(levels->exit.sprite);

    sfSound_play(window->click);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y))
        window->index = 0;
    level_picked(mouse, &levels->levels[0], window);
    level_picked(mouse, &levels->levels[1], window);
    level_picked(mouse, &levels->levels[2], window);
    level_picked(mouse, &levels->levels[3], window);
    level_picked(mouse, &levels->levels[4], window);
    level_picked(mouse, &levels->levels[5], window);
}

int analyse_level_events(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        window->index = 0;
    if (window->event.type == sfEvtMouseButtonPressed)
        level_mouse_event(&window->level_select,
        window->event.mouseButton, window);

}

void level_select2(window_t *window)
{
    button_hover_color_animation(window->mouse,
    &window->level_select.exit);
    button_hover_color_animation(window->mouse,
    &window->level_select.levels[0].icon);
    button_hover_color_animation(window->mouse,
    &window->level_select.levels[1].icon);
    button_hover_color_animation(window->mouse,
    &window->level_select.levels[2].icon);
    button_hover_color_animation(window->mouse,
    &window->level_select.levels[3].icon);
    button_hover_color_animation(window->mouse,
    &window->level_select.levels[4].icon);
    button_hover_color_animation(window->mouse,
    &window->level_select.levels[5].icon);
    sfRenderWindow_drawSprite(window->window,
    window->level_select.background.sprite, NULL);
}

void level_select3(window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->level_select.levels[0].icon.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->level_select.levels[1].icon.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->level_select.levels[2].icon.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->level_select.levels[3].icon.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->level_select.levels[4].icon.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->level_select.levels[5].icon.sprite, NULL);
}

void level_select(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_level_events(window);
    }
    level_select2(window);
    sfRenderWindow_drawSprite(window->window,
    window->level_select.menu.sprite, NULL);
    sfRenderWindow_drawSprite(window->window,
    window->level_select.exit.sprite, NULL);
    level_select3(window);
}