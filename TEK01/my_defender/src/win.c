/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** win
*/

#include "../include/include.h"

void init_win_menu(win_menu_t *win_menu, window_t *window)
{
    win_menu->background = init_sprite((sprite_info_t){0, 0, 1, 1, 0, 0, 1080,
    1920, "assets/menu/bg.png"});
    win_menu->window = init_sprite((sprite_info_t){650, 100, 1, 1, 0, 0, 0, 0,
    "assets/game_ui/win_menu.png"});
    win_menu->menu_button = init_sprite((sprite_info_t){695, 750, 1, 1, 0, 0,
    0, 0, "assets/menu/button_left.png"});
    win_menu->next = init_sprite((sprite_info_t){1175, 750, 1, 1, 0, 0, 0, 0,
    "assets/menu/button_right.png"});
    win_menu->played = 0;
    init_text(&win_menu->score, 100, "0", (sfVector2f){880, 450});
    sfText_setOutlineThickness(win_menu->score.text, 3);
    sfText_setOutlineColor(win_menu->score.text, sfBlack);
    init_text(&win_menu->golds, 60, "0", (sfVector2f){1000, 740});
    sfText_setOutlineThickness(win_menu->golds.text, 2);
    sfText_setOutlineColor(win_menu->golds.text, sfBlack);
    sound_set_audio(&win_menu->win_sound, "assets/music/win.ogg",
    window->sound_volume);
}

int win_menu_mouse_event(win_menu_t *win_menu, sfMouseButtonEvent mouse,
window_t *window)
{
    sfFloatRect return_box =
    sfSprite_getGlobalBounds(win_menu->menu_button.sprite);
    sfFloatRect next_box = sfSprite_getGlobalBounds(win_menu->next.sprite);

    sfSound_play(window->click);
    if (sfFloatRect_contains(&return_box, mouse.x, mouse.y)) {
        window->index = 0;
        win_menu->played = 0;
    }
    if (sfFloatRect_contains(&next_box, mouse.x, mouse.y) &&
    window->level.level < 12) {
        window->level = window->level_select.levels[window->level.level];
        init_game(&window->game, &window->clock, window);
        window->index = 2;
        win_menu->played = 0;
    }
}

int analyse_win_menu_events(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (window->event.type == sfEvtMouseButtonPressed)
        win_menu_mouse_event(&window->win_menu,
        window->event.mouseButton, window);
}

void win_menu2(window_t *window)
{
    button_hover_color_animation(window->mouse, &window->win_menu.next);
    button_hover_color_animation(window->mouse, &window->win_menu.menu_button);
    sfRenderWindow_drawSprite(window->window,
    window->win_menu.background.sprite, NULL);
    sfRenderWindow_drawSprite(window->window, window->win_menu.window.sprite,
    NULL);
    sfRenderWindow_drawSprite(window->window,
    window->win_menu.menu_button.sprite, NULL);
    sfText_setString(window->win_menu.golds.text,
    my_int_to_str(window->level.gold));
    sfRenderWindow_drawText(window->window, window->win_menu.golds.text, NULL);
}

void win_menu(window_t *window)
{
    int score = ((300 * (window->game.allies.hdv.health +
    window->game.allies.tower_1.health + window->game.allies.tower_2.health)) /
    (window->game.allies.hdv.max_health + window->game.allies.tower_1.max_health
    + window->game.allies.tower_2.max_health)) * 1000 / 300;

    sfMusic_stop(window->game.music);
    if (!window->win_menu.played) {
        sfSound_play(window->win_menu.win_sound);
        window->win_menu.played = 1;
    }
    while (sfRenderWindow_pollEvent(window->window, &window->event))
        analyse_win_menu_events(window);
    win_menu2(window);
    sfText_setString(window->win_menu.score.text, my_int_to_str(score));
    sfRenderWindow_drawText(window->window, window->win_menu.score.text, NULL);
    if (window->level.level < 12)
        sfRenderWindow_drawSprite(window->window, window->win_menu.next.sprite,
        NULL);
}