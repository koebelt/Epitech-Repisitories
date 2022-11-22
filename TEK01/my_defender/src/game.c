/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** game
*/

#include "../include/include.h"

int game_released_event(game_t *game, sfMouseButtonEvent mouse,
window_t *window)
{
    for (int i = 0; i < window->level.cards; i++)
        card_released(game, mouse, window, &game->ig_ui.cards[i]);
}

int analyse_game_events(window_t *window)
{
    if (window->event.type == sfEvtClosed)
        sfRenderWindow_close(window->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        window->index = 3;
    if (window->event.type == sfEvtMouseButtonPressed)
        game_mouse_event(&window->game, window->event.mouseButton, window);
    if (window->event.type == sfEvtMouseButtonReleased)
        game_released_event(&window->game, window->event.mouseButton, window);
}

void game2(window_t *window)
{
    sfRenderWindow_drawSprite(window->window,
    window->level.background.sprite, sfFalse);
    display_buildings(&window->game, window);

    print_soldiers(window->level.enemies.soldiers,
    window->window, &window->clock);
    delete_dead_soldiers(&window->level.enemies.soldiers);
    soldier_target(window->game.allies.soldiers,
    &window->level.enemies, &window->clock);

    print_soldiers(window->game.allies.soldiers,
    window->window, &window->clock);
    delete_dead_soldiers(&window->game.allies.soldiers);
    soldier_target(window->level.enemies.soldiers,
    &window->game.allies, &window->clock);
}

void game(window_t *window)
{
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        analyse_game_events(window);
    }
    sfMusic_stop(window->menu.music);
    if (window->game.has_started) {
        if (!sfMusic_getStatus(window->game.music))
            sfMusic_play(window->game.music);
        display_energy(&window->level.enemies.energy, window);
        ai_place_monster(window);
    }
    game2(window);

    display_ig_ui(&window->game.ig_ui, window);
    if (window->game.has_started) {
        display_energy(&window->game.allies.energy, window);
    } else
        disp_choosing(&window->game, window);
    if (window->level.enemies.hdv.health <= 0)
        window->index = 4;
    if (window->game.allies.hdv.health <= 0)
        window->index = 5;
}